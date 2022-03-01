
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
            this.inputTextbox = new System.Windows.Forms.TextBox();
            this.resultTextbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // inputTextbox
            // 
            this.inputTextbox.Dock = System.Windows.Forms.DockStyle.Top;
            this.inputTextbox.Font = new System.Drawing.Font("Consolas", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.inputTextbox.Location = new System.Drawing.Point(0, 0);
            this.inputTextbox.Multiline = true;
            this.inputTextbox.Name = "inputTextbox";
            this.inputTextbox.Size = new System.Drawing.Size(800, 273);
            this.inputTextbox.TabIndex = 0;
            this.inputTextbox.Text = "class ABCD{  \r\n    public void qwerty  (qqwrwe dfdfg);\r\n    public string somemet" +
    "hod (int param);\r\n    public static int iamstatic ();\r\n}";
            this.inputTextbox.KeyUp += new System.Windows.Forms.KeyEventHandler(this.inputTextbox_KeyUp);
            // 
            // resultTextbox
            // 
            this.resultTextbox.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.resultTextbox.Font = new System.Drawing.Font("Consolas", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.resultTextbox.Location = new System.Drawing.Point(0, 324);
            this.resultTextbox.Multiline = true;
            this.resultTextbox.Name = "resultTextbox";
            this.resultTextbox.Size = new System.Drawing.Size(800, 126);
            this.resultTextbox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 303);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 18);
            this.label1.TabIndex = 2;
            this.label1.Text = "Result";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.resultTextbox);
            this.Controls.Add(this.inputTextbox);
            this.Name = "Form1";
            this.Text = "Regular expressions";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox inputTextbox;
    private System.Windows.Forms.TextBox resultTextbox;
    private System.Windows.Forms.Label label1;
}
