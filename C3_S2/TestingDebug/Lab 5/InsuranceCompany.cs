using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Windows.Forms;

namespace Lab_5
{
    public class InsuranceCompany
    {
        private List<InsuranceType> _insuranceTypes = new List<InsuranceType>();
        private List<Branch> _branches = new List<Branch>();
        private List<Contracts> _contracts = new List<Contracts>();

        public List<InsuranceType> InsuranceTypes
        {
            get { return _insuranceTypes; }
            set { _insuranceTypes = value; }
        }

        public List<Branch> Branches
        {
            get { return _branches; }
            set { _branches = value; }
        }

        public List<Contracts> Contracts
        {
            get { return _contracts; }
            set { _contracts = value; }
        }

        public List<Contracts> GetContractsByInsuranceType(InsuranceType insuranceType)
        {
            var contracts = new List<Contracts>();
            contracts.AddRange(_contracts.Where(c => c.InsuranceType == insuranceType).ToList());
            return contracts;
        }

        public bool Conclude(string contractNumber, decimal insuranceSum, decimal tariffRate,
            Branch branch, InsuranceType insuranceType)
        {
            var flag = false;
            var now = DateTime.Now;

            const decimal maxLimit = 1000000M;

            if (insuranceSum < maxLimit)
            {
                var contract = new Contracts
                {
                    ContractNumber = contractNumber,
                    ConclusionDate = now,
                    InsuranceSum = insuranceSum,
                    TariffRate = tariffRate,
                    Branch = branch,
                    InsuranceType = insuranceType
                };
                _contracts.Add(contract);
                flag = true;
            }

            return flag;
        }

        public bool Terminate(TimeSpan timeStamp)
        {
            var flag = false;
            var now = DateTime.Now;
            var contract = _contracts.FirstOrDefault(c => (now - c.ConclusionDate).TotalDays > timeStamp.TotalDays);

            if (contract != null)
            {
                _contracts.Remove(contract);
                flag = true;
            }
            return flag;
        }
    }
}
