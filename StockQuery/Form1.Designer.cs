namespace CSWS
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.RestfulButton = new System.Windows.Forms.Button();
			this.StockInfoText = new System.Windows.Forms.TextBox();
			this.StockImage = new System.Windows.Forms.PictureBox();
			this.SoapButton = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.SourcePathLable = new System.Windows.Forms.Label();
			this.StockCodeEdit = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.StockImage)).BeginInit();
			this.SuspendLayout();
			// 
			// RestfulButton
			// 
			this.RestfulButton.Location = new System.Drawing.Point(454, 510);
			this.RestfulButton.Name = "RestfulButton";
			this.RestfulButton.Size = new System.Drawing.Size(75, 23);
			this.RestfulButton.TabIndex = 0;
			this.RestfulButton.Text = "Restful";
			this.RestfulButton.UseVisualStyleBackColor = true;
			this.RestfulButton.Click += new System.EventHandler(this.RestfulButton_Click);
			// 
			// StockInfoText
			// 
			this.StockInfoText.Location = new System.Drawing.Point(46, 76);
			this.StockInfoText.Multiline = true;
			this.StockInfoText.Name = "StockInfoText";
			this.StockInfoText.Size = new System.Drawing.Size(581, 52);
			this.StockInfoText.TabIndex = 1;
			this.StockInfoText.Text = "No Response";
			// 
			// StockImage
			// 
			this.StockImage.Location = new System.Drawing.Point(46, 163);
			this.StockImage.Name = "StockImage";
			this.StockImage.Size = new System.Drawing.Size(581, 310);
			this.StockImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
			this.StockImage.TabIndex = 2;
			this.StockImage.TabStop = false;
			// 
			// SoapButton
			// 
			this.SoapButton.Location = new System.Drawing.Point(552, 510);
			this.SoapButton.Name = "SoapButton";
			this.SoapButton.Size = new System.Drawing.Size(75, 23);
			this.SoapButton.TabIndex = 3;
			this.SoapButton.Text = "SOAP";
			this.SoapButton.UseVisualStyleBackColor = true;
			this.SoapButton.Click += new System.EventHandler(this.SoapButton_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(34, 16);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(41, 13);
			this.label1.TabIndex = 5;
			this.label1.Text = "Source";
			// 
			// SourcePathLable
			// 
			this.SourcePathLable.Location = new System.Drawing.Point(106, 16);
			this.SourcePathLable.Name = "SourcePathLable";
			this.SourcePathLable.Size = new System.Drawing.Size(537, 32);
			this.SourcePathLable.TabIndex = 6;
			this.SourcePathLable.Text = "label2";
			// 
			// StockCodeEdit
			// 
			this.StockCodeEdit.Location = new System.Drawing.Point(203, 509);
			this.StockCodeEdit.Name = "StockCodeEdit";
			this.StockCodeEdit.Size = new System.Drawing.Size(115, 20);
			this.StockCodeEdit.TabIndex = 7;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(46, 512);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(138, 13);
			this.label2.TabIndex = 8;
			this.label2.Text = "Stock Code(E.g. sh000001)";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(679, 557);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.StockCodeEdit);
			this.Controls.Add(this.SourcePathLable);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.SoapButton);
			this.Controls.Add(this.StockImage);
			this.Controls.Add(this.StockInfoText);
			this.Controls.Add(this.RestfulButton);
			this.Name = "Form1";
			this.Text = "Form1";
			((System.ComponentModel.ISupportInitialize)(this.StockImage)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button RestfulButton;
		private System.Windows.Forms.TextBox StockInfoText;
		private System.Windows.Forms.PictureBox StockImage;
		private System.Windows.Forms.Button SoapButton;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label SourcePathLable;
		private System.Windows.Forms.TextBox StockCodeEdit;
		private System.Windows.Forms.Label label2;
	}
}