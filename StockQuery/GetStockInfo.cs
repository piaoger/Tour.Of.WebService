using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using ChinaStockWebService.cn.com.webxml.www;
using System.Drawing;
using System.Net;

using System.Windows.Forms;

namespace CSWS
{
	// // 61.147.124.120
	//
	class SoapQuery
	{
		public static string GetSource()
        {
			return "http://www.webxml.com.cn/WebServices/ChinaStockWebService.asmx";
		}

		// getStockInfo
		//
		public static string GetStockInfo(string code)
		{

			ChinaStockWebService.cn.com.webxml.www.ChinaStockWebService oService = new ChinaStockWebService.cn.com.webxml.www.ChinaStockWebService();
			string[] info_byte = oService.getStockInfoByCode(code);

			string strInfo = "";
			foreach (string strLine in info_byte)
			{
				strInfo = strInfo + "\n" + strLine;
			}

			return strInfo;
		}

		// Save Stock Image to local file
		//
		public static void GetStockImage(string code, string filename)
		{
            //ChinaStockWebService.cn.com.webxml.www.ChinaStockWebService oService = new ChinaStockWebService.cn.com.webxml.www.ChinaStockWebService();
            //byte[] image_bytes = oService.getStockImageByteByCode(code);

            //Image image = CovertUtil.byteArrayToImage(image_bytes);
            //image.Save(filename);
		}

	};

	// CommView HTTP Analyzer

	//POST /WebServices/ChinaStockWebService.asmx HTTP/1.1
	//User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; MS Web Services Client Protocol 2.0.50727.3603)
	//VsDebuggerCausalityData: uIDPowOEuUJZbqRJtxAFcA/WSHkAAAAA1gzbkv7ONEGsZ5se4/oaBJ00bq++H01LmgVGJKWdaA4ACQAA
	//Content-Type: text/xml; charset=utf-8
	//SOAPAction: "http://WebXml.com.cn/getStockInfoByCode"
	//Host: www.webxml.com.cn
	//Content-Length: 354
	//Expect: 100-continue
	//Connection: Keep-Alive

	//HTTP/1.1 100 Continue

	//<?xml version="1.0" encoding="utf-8"?><soap:Envelope xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema"><soap:Body><getStockInfoByCode xmlns="http://WebXml.com.cn/"><theStockCode>sh000001</theStockCode></getStockInfoByCode></soap:Body></soap:Envelope>HTTP/1.1 200 OK
	//Date: Mon, 16 Aug 2010 07:44:34 GMT
	//Server: Microsoft-IIS/6.0
	//X-Powered-By: ASP.NET
	//X-AspNet-Version: 2.0.50727
	//Cache-Control: private, max-age=0
	//Content-Type: text/xml; charset=utf-8
	//Content-Length: 832

	//<?xml version="1.0" encoding="utf-8"?><soap:Envelope xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema"><soap:Body><getStockInfoByCodeResponse xmlns="http://WebXml.com.cn/"><getStockInfoByCodeResult><string>sh000001</string><string>ä¸Šè¯æŒ‡æ•°</string><string>2010-08-16 15:03:09</string><string>2661.708</string><string>2606.700</string><string>2603.792</string><string>55.01</string><string>2596.771</string><string>2665.314</string><string>2.11%</string><string>1258628.23</string><string>13073685.1353</string><string /><string /><string /><string /><string /><string /><string /><string /><string /><string /><string /><string /><string /></getStockInfoByCodeResult></getStockInfoByCodeResponse></soap:Body></soap:Envelope>



	// 60.28.0.266

	class RESTfulQuery
	{
		public static string GetSource()
		{
			return "http://hq.sinajs.cn";
		}

		public static string GetStockInfo(string code)
		{
			string uri = "http://hq.sinajs.cn/list=" + code;

			HttpWebRequest request = CreateWebRequest(uri);
			//request.TransferEncoding = "GBK";
			HttpWebResponse response = (HttpWebResponse)request.GetResponse();


			StreamReader responsestream = new StreamReader(response.GetResponseStream(), Encoding.GetEncoding("GBK"));
			return responsestream.ReadToEnd();
		}

		// Save Stock Image to local file
		public static void GetStockImage(string code, string filename)
		{
			string uri = "http://image.sinajs.cn/newchart/daily/n/" + code + ".gif";

			try
			{
				HttpWebRequest request = CreateWebRequest(uri);

				HttpWebResponse response = (HttpWebResponse)request.GetResponse();
				Image image = Image.FromStream(response.GetResponseStream());
				image.Save(filename);
			}
			catch (Exception e)
			{
				MessageBox.Show("Failed to query Stock infromation");
				filename = "";
			}
		}

		public static HttpWebRequest CreateWebRequest(string uri)
		{
			return (HttpWebRequest)WebRequest.Create(uri);
		}
	};

	//GET /list=sh000001 HTTP/1.1
	//Host: hq.sinajs.cn

	//HTTP/1.1 200 OK
	//Cache-Control: no-cache
	//Content-Length: 164
	//Connection: Keep-Alive
	//Content-Type: application/x-javascript; charset=GBK

	//var hq_str_sh000001="ÉÏÖ¤Ö¸Êý,2603.792,2606.700,2661.708,2665.314,2596.771,0,0,125862823,130736851353,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2010-08-16,15:03:09";


}

