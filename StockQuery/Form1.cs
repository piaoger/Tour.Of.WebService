using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
 

namespace CSWS
{
	public partial class Form1 : Form
	{
		private string mFileName;
		public Form1()
		{
			InitializeComponent();
			string time_string = DateTime.Now.Second.ToString(); 
			mFileName = "c:\\stockImage[" + time_string + "].gif";
			this.StockCodeEdit.Text =  "sh000001";

		}

		private void RestfulButton_Click(object sender, EventArgs e)
		{
			string strStockCode = this.StockCodeEdit.Text;
			this.SourcePathLable.Text = RESTfulQuery.GetSource();
			RESTfulQuery.GetStockImage(strStockCode, mFileName);
			this.StockInfoText.Text = RESTfulQuery.GetStockInfo(strStockCode);
			this.StockImage.ImageLocation = mFileName;
			this.StockImage.SizeMode = PictureBoxSizeMode.AutoSize;
		}

		private void SoapButton_Click(object sender, EventArgs e)
		{
			string strStockCode = this.StockCodeEdit.Text;
			this.SourcePathLable.Text = SoapQuery.GetSource();
			 SoapQuery.GetStockImage(strStockCode, mFileName);
				this.StockInfoText.Text = SoapQuery.GetStockInfo(strStockCode);
			this.StockImage.ImageLocation = mFileName;
			this.StockImage.SizeMode = PictureBoxSizeMode.AutoSize;
		}
 

	 
	}

}
