using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab13
{
    #region Mocks

    public class CatalogMock
    {
        public static List<InsuranceType> GetTypes()
        {
            var types = new List<InsuranceType>();
            types.Add(new InsuranceType { Id = 1, Type = "Type1" });
            types.Add(new InsuranceType { Id = 2, Type = "Type2" });
            types.Add(new InsuranceType { Id = 3, Type = "Type3" });
            return types;
        }
    }

    public class ContractMock
    {
        public static bool AddContract(DateTime date, decimal insuranceAmount,
            decimal tarrifRate, int type_id)
        {
            var contract = new Contract
            {
                Date = date,
                InsuranceAmount = insuranceAmount,
                TarrifRate = tarrifRate,
                InsuranceType_Id = type_id
            };

            return true;
        }
    }

    public class SearchMock
    {
        public static List<Contract> FindContracts(int type)
        {
            List<Contract> contracts = new List<Contract>();

            contracts.Add(new Contract
            {
                Date = DateTime.Today,
                InsuranceAmount = 1000m,
                TarrifRate = 0.9m,
                InsuranceType_Id = 1
            });

            return contracts;
        }
    }

    #endregion Mocks

    public class Catalog
    {
        public static List<InsuranceType> GetInsuranceTypes()
        {
            //var entities = new Lab11_DBEntities();
            //List<InsuranceType> types = entities.InsuranceTypes.ToList();
            //return types;

            var types = new List<InsuranceType>();
            types.Add(new InsuranceType { Id = 1, Type = "Type1" });
            types.Add(new InsuranceType { Id = 2, Type = "Type2" });
            types.Add(new InsuranceType { Id = 3, Type = "Type3" });
            return types;
        }
    }

    public class Contracts
    {
        public static bool AddContract(DateTime date, decimal insuranceAmount,
            decimal tarrifRate, int type_id)
        {
            //var entities = new Lab11_DBEntities();
            //var contract = new Contract
            //{
            //    Date = date,
            //    InsuranceAmount = insuranceAmount,
            //    TarrifRate = tarrifRate,
            //    InsuranceType_Id = type_id
            //};

            //entities.Contracts.Add(contract);
            //entities.SaveChanges();
            //return true;

            var contract = new Contract
            {
                Date = date,
                InsuranceAmount = insuranceAmount,
                TarrifRate = tarrifRate,
                InsuranceType_Id = type_id
            };

            return true;
        }
    }

    public class Search
    {
        public static List<Contract> FindContracts(int type)
        {
            //var entities = new Lab11_DBEntities();
            //List<Contract> contracts = new List<Contract>();
            //contracts = entities.Contracts.Where(b => b.InsuranceType_Id == type).ToList();
            //return contracts;

            List<Contract> contracts = new List<Contract>();

            contracts.Add(new Contract
            {
                Date = DateTime.Today,
                InsuranceAmount = 1000m,
                TarrifRate = 0.9m,
                InsuranceType_Id = 1
            });

            return contracts;
        }
    }

    public partial class Form1 : Form
    {
        Lab11_DBEntities _entities = new Lab11_DBEntities();
        List<InsuranceType> _insuranceTypes = new List<InsuranceType>();
        public Form1()
        {
            try
            {
                InitializeComponent();
                dateTimePickerAdd.MaxDate = DateTime.Today;
                dateTimePickerAdd.Value = DateTime.Today;
                comboBoxTarrifFind.DisplayMember = comboBoxTarrifAdd.DisplayMember = "Type";
                comboBoxTarrifFind.ValueMember = comboBoxTarrifAdd.ValueMember = "Id";

                _insuranceTypes = _entities.InsuranceTypes.ToList();
                
                foreach (var type in _insuranceTypes) {
                    comboBoxTarrifAdd.Items.Add(type);
                    comboBoxTarrifFind.Items.Add(type);
                }

                
            }
            catch (Exception exception)
            {
                MessageBox.Show("При подключении к БД произошла ошибка. Проверьте подключение и перезапустите программу.");
                Application.Exit();
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                Contract contract = new Contract();
                contract.Date = dateTimePickerAdd.Value;
                contract.InsuranceAmount = numericUpDownSumAdd.Value;
                contract.TarrifRate = numericUpDownTarrifRateAdd.Value;
                contract.InsuranceType_Id = ((InsuranceType)comboBoxTarrifAdd.SelectedItem).Id;
                _entities.Contracts.Add(contract);
                _entities.SaveChanges();

                MessageBox.Show("Контракт был успешно добавлен.");
            }
            catch (Exception exception)
            {
                MessageBox.Show(string.Format(@"Во время добавления произошла ошибка ({0}). Проверьте подключение к БД и корректность введенных данных и повторите попытку", exception.Message));
            }
        }

        private void buttonFind_Click(object sender, EventArgs e)
        {
            try
            {
                var searchTarrif = ((InsuranceType)comboBoxTarrifFind.SelectedItem).Id;
                List<Contract> _contracts = new List<Contract>();
                _contracts = _entities.Contracts.Where(b => b.InsuranceType_Id == searchTarrif).ToList();

                dataGridViewFind.DataSource = _contracts;
            }
            catch (Exception exception)
            {
                MessageBox.Show(string.Format(@"Во время поиска произошла ошибка ({0})", exception.Message));
            }
        }

    }
}
