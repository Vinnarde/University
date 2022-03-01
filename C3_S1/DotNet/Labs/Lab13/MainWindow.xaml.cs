using System;
using System.Data;
using System.IO;
using System.Windows;
using System.Windows.Data;
using System.Windows.Input;
using Microsoft.Win32;

namespace Lab13
{
    public partial class MainWindow : Window
    {
        Lab13DataSet _dataSet;
        TableAdapters.teachersTableAdapter _teachersAdapter;
        TableAdapters.degreesTableAdapter _degreesAdapter;

        public MainWindow()
        {
            
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            _dataSet = (Lab13DataSet)FindResource("lab13DataSet");

            _teachersAdapter = new TableAdapters.teachersTableAdapter();
            _teachersAdapter.Fill(_dataSet.teachers);
            CollectionViewSource teachersViewSource = (CollectionViewSource)FindResource("teachersViewSource");
            teachersViewSource.View.MoveCurrentToFirst();
            
            _degreesAdapter = new TableAdapters.degreesTableAdapter();
            _degreesAdapter.Fill(_dataSet.degrees);
            CollectionViewSource degreesViewSource = (CollectionViewSource)FindResource("degreesViewSource");
            degreesViewSource.View.MoveCurrentToFirst();
        }

        private void DeleteRecord_Click(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < TeachersGrid.SelectedItems.Count; i++)
            {
                if (TeachersGrid.SelectedItems[i] is DataRowView rowView)
                {
                    DataRow row = rowView.Row;
                    row.Delete();
                }   
            }
            _teachersAdapter.Update(_dataSet.teachers);
        }

        private void SaveChangesToDB()
        {
            _degreesAdapter.Update(_dataSet.degrees);
            _teachersAdapter.Update(_dataSet.teachers);
            MessageBox.Show("Changes saved!");
        }

        private void UploadPhoto_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                DefaultExt = ".jpg",
                Filter = "Image Files(*.jpg; *.jpeg)|*.jpg; *.jpeg;"
            };

            if (openFileDialog.ShowDialog() == true)
            {
                if (TeachersGrid.SelectedItems.Count > 0)
                {
                    if (TeachersGrid.SelectedItems[0] is DataRowView dataRowView)
                    {
                        if (dataRowView.Row is Lab13DataSet.teachersRow dataRow)
                        {
                            dataRow.photo = File.ReadAllBytes(openFileDialog.FileName);
                        }
                    }
                }
            }
        }

        private void RemovePhoto_Click(object sender, RoutedEventArgs e)
        {
            if (TeachersGrid.SelectedItems.Count > 0)
            {
                if (TeachersGrid.SelectedItems[0] is DataRowView dataRowView)
                {
                    if (dataRowView.Row is Lab13DataSet.teachersRow dataRow)
                    {
                        dataRow.photo = null;
                    }
                }
            }
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            if (Keyboard.Modifiers == ModifierKeys.Control && e.Key == Key.S)
            {
                SaveChangesToDB();
            }
        }
    }
}
