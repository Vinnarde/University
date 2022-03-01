
partial class Form
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
            this.booksList = new System.Windows.Forms.ListView();
            this.createButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // booksList
            // 
            this.booksList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.booksList.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.booksList.FullRowSelect = true;
            this.booksList.GridLines = true;
            this.booksList.HideSelection = false;
            this.booksList.Location = new System.Drawing.Point(0, 0);
            this.booksList.MultiSelect = false;
            this.booksList.Name = "booksList";
            this.booksList.Size = new System.Drawing.Size(621, 404);
            this.booksList.TabIndex = 0;
            this.booksList.UseCompatibleStateImageBehavior = false;
            this.booksList.View = System.Windows.Forms.View.List;
            this.booksList.DoubleClick += new System.EventHandler(this.booksList_DoubleClick);
            this.booksList.KeyUp += new System.Windows.Forms.KeyEventHandler(this.booksList_KeyUp);
            // 
            // createButton
            // 
            this.createButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.createButton.Location = new System.Drawing.Point(501, 350);
            this.createButton.Name = "createButton";
            this.createButton.Size = new System.Drawing.Size(103, 38);
            this.createButton.TabIndex = 1;
            this.createButton.Text = "+ CREATE";
            this.createButton.UseVisualStyleBackColor = true;
            this.createButton.Click += new System.EventHandler(this.createButton_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(621, 404);
            this.Controls.Add(this.createButton);
            this.Controls.Add(this.booksList);
            this.Name = "Form";
            this.Text = "Client";
            this.Load += new System.EventHandler(this.Form_Load);
            this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.ListView booksList;
    private System.Windows.Forms.Button createButton;
}

