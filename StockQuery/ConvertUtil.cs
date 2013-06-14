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
	class CovertUtil
	{
		public static byte[] imageToByteArray(System.Drawing.Image imageIn)
		{
			MemoryStream ms = new MemoryStream();
			imageIn.Save(ms, System.Drawing.Imaging.ImageFormat.Gif);
			return ms.ToArray();
		}

		public static Image byteArrayToImage(byte[] byteArrayIn)
		{
			MemoryStream ms = new MemoryStream(byteArrayIn);
			Image returnImage = Image.FromStream(ms);
			return returnImage;
		}


		public static byte[] StreamToBytes(Stream stream)
		{
			byte[] bytes = new byte[stream.Length];
			stream.Read(bytes, 0, (int)stream.Length);

			//stream.Seek(0, SeekOrigin.Begin);
			return bytes;
		}

		public static Stream BytesToStream(byte[] bytes)
		{
			Stream stream = new MemoryStream(bytes);
			return stream;
		}

	};

 

}

