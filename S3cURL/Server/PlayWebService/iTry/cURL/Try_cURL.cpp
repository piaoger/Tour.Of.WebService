 
#include <PlayWebService/Global/Global.h>

#include <tut.h>

#include <cURL/curl.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

#include <cstdio>
#include <iostream>

namespace tut 
{ 
    struct test_playwebservice_curl_data
    {
        static size_t processData(void *buffer, size_t size, size_t nmemb, void *user_p)
        {
            FILE *fp = (FILE*)user_p;
            size_t return_size = fwrite(buffer, size, nmemb, fp);
            return return_size;
        }

        /// IOBuffer Node
        typedef struct _IOBufferNode
        {
            char * buf;
            struct _IOBufferNode * next;
        } IOBufferNode;

        /// IOBuffer structure
        typedef struct IOBuffer 
        {
            IOBufferNode* first;
            IOBufferNode* current;
            char* pos;

            char* result;
            char* lastMod;
            char* eTag;
            int contentLen;
            int len;
            int code;
        } IOBuffer;

        static size_t curlHeaderFunction ( void * ptr, size_t size, size_t nmemb, void * stream )
        {
            return nmemb * size;
        }

        static void appendAwsIoBuffer(IOBuffer* B, char* d, int len)
        {
            IOBufferNode * N = (IOBufferNode *)malloc(sizeof(IOBufferNode));
            N->next = NULL;
            N->buf  =(char*) malloc(len+1);
            memcpy(N->buf,d,len);
            N->buf[len] = 0;
            B->len += len;

            if ( B->first == NULL ) {
                B->first   = N;
                B->current = N;
                B->pos     = N->buf;
            } else {
                // Find the last block
                IOBufferNode * D = B->first;
                while(D->next != NULL ) D = D->next;
                D->next = N;
            }
        }

        static size_t curlWriteFunction ( void * ptr, size_t size, size_t nmemb, void * stream )
        {
            appendAwsIoBuffer ((IOBuffer*) stream, (char*)ptr, nmemb * size );
            return nmemb * size;
        }

    };

    typedef test_group<test_playwebservice_curl_data> TestGroup;
    TestGroup ThisTestGroup("Try LibCURL");

    typedef TestGroup::object TestObject;

    template<> 
    template<> 
    void TestObject::test<1>() 
    {
        set_test_name("A simple case: Get Page Content and save to file");

        // Initialize libcurl
        CURLcode return_code;
        return_code = curl_global_init(CURL_GLOBAL_WIN32);
        if (CURLE_OK != return_code) {
            std::cerr << "init libcurl failed." << std::endl;
            return ;
        }

        // Get easy handle
        CURL *easy_handle = curl_easy_init();
        if (NULL == easy_handle) {
            std::cerr << "get a easy handle failed." << std::endl;
            curl_global_cleanup();
            return ;
        }

        FILE *fp = fopen("c:\\TrycURL_1.html", "wb+");    // 

        // Set easy handle properties
        curl_easy_setopt(easy_handle, CURLOPT_URL, "http://curl.haxx.se/docs/thanks.html");
        curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &processData);
        curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, fp);

        // Tells the library to include the header in the body output. 
        curl_easy_setopt(easy_handle, CURLOPT_AUTOREFERER, 1);

        // Perform Request
        curl_easy_perform(easy_handle);

        char* ip_str = NULL;
        return_code = curl_easy_getinfo(easy_handle, CURLINFO_PRIMARY_IP, &ip_str);
        std::cout << "Primary IP : " << ip_str<<std::endl;

        char* url_str = NULL;
        return_code = curl_easy_getinfo(easy_handle, CURLINFO_EFFECTIVE_URL, &url_str);
        std::cout << "Effective URL : " << url_str<<std::endl;

        long* http_code = NULL;
        return_code = curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &http_code);

        long* httpproxy_code = NULL;
        return_code = curl_easy_getinfo(easy_handle, CURLINFO_HTTP_CONNECTCODE, &httpproxy_code);

        // Close File ane clean up curl
        fclose(fp);

        curl_easy_cleanup(easy_handle);
        curl_global_cleanup();
    } 


    template<> 
    template<> 
    void TestObject::test<2>() 
    {
        set_test_name("Try multiple handle of libcurl.");

        CURLcode return_code = curl_global_init(CURL_GLOBAL_ALL);
        if(return_code != CURLE_OK) {
            std::cerr << "init libcurl failed." << std::endl;
            return ;
        }

        CURL* easy_handle = curl_easy_init();
        curl_easy_setopt(easy_handle, CURLOPT_URL, "http://ghr.nlm.nih.gov/handbook.pdf");

        CURLM *multi_handle = curl_multi_init();

        curl_multi_add_handle(multi_handle, easy_handle);

        int running=1;
        while (running) {
            curl_multi_perform(multi_handle, &running);
            if (running <= 0) {
                break;
            }
        }

        if(multi_handle) {
            curl_multi_remove_handle(multi_handle, easy_handle);
            curl_multi_cleanup(multi_handle);
        }

        curl_easy_cleanup(easy_handle);
        curl_global_cleanup();
    }

    template<> 
    template<> 
    void TestObject::test<3>() 
    {
        set_test_name("Try to use LibCurl for RESTful webservice of Amazon S3");    

        //thorization = "AWS" + " " + AWSAccessKeyId + ":" + Signature;
        //
        //Signature = Base64( HMAC-SHA1( UTF-8-Encoding-Of( StringToSign ) ) );
        //
        //StringToSign = HTTP-Verb + "\n" +
        //    Content-MD5 + "\n" +
        //    Content-Type + "\n" +
        //    Date + "\n" +
        //    CanonicalizedAmzHeaders +
        //    CanonicalizedResource;
        //
        //CanonicalizedResource = [ "/" + Bucket ] +
        //    <HTTP-Request-URI, from the protocol name up to the query string> +
        //    [ sub-resource, if present. For example "?acl", "?location", "?logging", or "?torrent"];
        //
        //CanonicalizedAmzHeaders = <described below>
    
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // You have to provide your own keys and resource name here
        assert(0);
        char* keyId = "Access key Id";
        char* accessKey = "Secret Access Key";
        char* resourceName = "bucket/folder/file.txt";

        char* hostId = "s3.amazonaws.com";

        curl_global_init (CURL_GLOBAL_ALL);

        // Method
        char * const method = "HEAD";

        // DateTime
        static char dTime[256];
        time_t t = time(NULL);
        struct tm * gTime = gmtime ( & t );
        memset ( dTime, 0 , sizeof(dTime));
        strftime ( dTime, sizeof(dTime), "%a, %d %b %Y %H:%M:%S +0000", gTime );

        // ACL
        char  acl[32];
        acl[0] = 0;

        // Bucket/FileName
        //
        char  resource [1024];
        snprintf ( resource, sizeof(resource),"%s", resourceName);

        char  reqToSign[2048];
        snprintf ( reqToSign,
                   sizeof(reqToSign),
                   "%s\n\n%s\n%s\n%s/%s", 
                   "GET",    // Method
                   "",
                   dTime,
                   acl,
                   resource);

        // Signature = Base64( HMAC-SHA1( UTF-8-Encoding-Of( StringToSign ) ) );

        // SHA1 Encoding: AWS Secret Access Key
        //
        HMAC_CTX ctx;
        unsigned char MD[256];
        unsigned len;

        HMAC_CTX_init(&ctx);
        HMAC_Init(&ctx, accessKey, strlen(accessKey), EVP_sha1());
        HMAC_Update(&ctx,(unsigned char*)reqToSign, strlen(reqToSign));
        HMAC_Final(&ctx,(unsigned char*)MD, &len);
        HMAC_CTX_cleanup(&ctx);

        // Base 64
        //
        BIO *bmem, *b64;
        BUF_MEM *bptr;

        b64  = BIO_new(BIO_f_base64());
        bmem = BIO_new(BIO_s_mem());
        b64  = BIO_push(b64, bmem);
        BIO_write(b64, MD, len);
        if(BIO_flush(b64)); /* make gcc 4.1.2 happy */
        BIO_get_mem_ptr(b64, &bptr);

        char *signature = (char *)malloc(bptr->length);
        memcpy(signature, bptr->data, bptr->length-1);
        signature[bptr->length-1] = 0;
        BIO_free_all(b64);

        // Initialize CURL Easy Interface
        CURL* pEasyHandle =  curl_easy_init( );

        // Populate curl_slist for StringToSign
        //
        struct curl_slist *slist=NULL;
        char Buf[1024];
        snprintf ( Buf, sizeof(Buf), "Date: %s", dTime );
        slist = curl_slist_append(slist, Buf );
        snprintf ( Buf, sizeof(Buf), "Authorization: AWS %s:%s", keyId, signature );
        slist = curl_slist_append(slist, Buf );
        
        // Get URL
        char url[1024];
        snprintf ( url, sizeof(url), "http://%s/%s", hostId, resource );

        IOBuffer* io_buf = (IOBuffer*)malloc(sizeof(IOBuffer));
        memset(io_buf, 0, sizeof(IOBuffer));

        curl_easy_setopt ( pEasyHandle, CURLOPT_HTTPHEADER, slist);
        curl_easy_setopt ( pEasyHandle, CURLOPT_URL, url );
        curl_easy_setopt ( pEasyHandle, CURLOPT_WRITEFUNCTION, curlWriteFunction );
        curl_easy_setopt ( pEasyHandle, CURLOPT_WRITEDATA, io_buf);
        curl_easy_setopt ( pEasyHandle, CURLOPT_HEADERFUNCTION, curlHeaderFunction);
        curl_easy_setopt ( pEasyHandle, CURLOPT_HEADERDATA, io_buf);

        curl_easy_perform(pEasyHandle);

        // clean up
        curl_slist_free_all(slist);
        curl_easy_cleanup(pEasyHandle);
    }
};