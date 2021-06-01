using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Договоры(номер договора, дата заключения, страховая сумма, тарифная ставка, филиал, вид страхования).

namespace Lab_5
{
    public class Contracts
    {
        public string ContractNumber { get; set; }
        public DateTime ConclusionDate { get; set; }
        public decimal InsuranceSum { get; set; }
        public decimal TariffRate { get; set; }
        public Branch Branch { get; set; }
        public InsuranceType InsuranceType { get; set; }


    }
}
