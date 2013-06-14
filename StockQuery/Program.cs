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
	class Program
	{
		static void Main(string[] args)
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new Form1());
		}
	}
}

