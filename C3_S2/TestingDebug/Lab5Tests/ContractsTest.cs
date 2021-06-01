using System;
using System.Collections.Generic;
using System.Text;
using Lab_5;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Lab5Tests
{
    /// <summary>
    ///Это класс теста для ClientTest, в котором должны
    ///находиться все модульные тесты ClientTest
    ///</summary>
    [TestClass]
    public class ContractsTest
    {
        /// <summary>
        ///Получает или устанавливает контекст теста, в котором предоставляются
        ///сведения о текущем тестовом запуске и обеспечивается его функциональность.
        ///</summary>
        public TestContext TestContext { get; set; }

        /// <summary>
        ///Тест для Конструктор Contracts
        ///</summary>
        [TestMethod]
        public void ContractsConstructorTest()
        {
            var target = new Contracts();
            Assert.IsInstanceOfType(target, typeof(Contracts));
        }

        /// <summary>
        ///Тест для ContractNumber
        ///</summary>
        [TestMethod]
        public void ContractsContractNumberTest()
        {
            var target = new Contracts();
            const string expected = "№-2051";
            target.ContractNumber = expected;
            string actual = target.ContractNumber;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для ConclusionDate
        ///</summary>
        [TestMethod]
        public void ContractsConclusionDateTest()
        {
            var target = new Contracts();
            DateTime expected = DateTime.Now; 
            target.ConclusionDate = expected;
            DateTime actual = target.ConclusionDate;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для InsuranceSum
        ///</summary>
        [TestMethod]
        public void ContractsInsuranceSumTest()
        {
            var target = new Contracts();
            const decimal expected = 527400.98M;
            target.InsuranceSum = expected;
            decimal actual = target.InsuranceSum;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для TariffRate
        ///</summary>
        [TestMethod]
        public void ContractsTariffRateTest()
        {
            var target = new Contracts();
            const decimal expected = 1.29M;
            target.TariffRate = expected;
            decimal actual = target.TariffRate;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для Branch
        ///</summary>
        [TestMethod]
        public void ContractsBranchTest()
        {
            var target = new Contracts();
            Branch expected = new Branch{ Name = "Филиал 1", Address = "Ул. Пушкина д.10 кв.123" , Phone = "8-800-555-35-35" };
            target.Branch = expected;
            Branch actual = target.Branch;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для InsuranceType
        ///</summary>
        [TestMethod]
        public void ContractsInsuranceTypeTest()
        {
            var target = new Contracts();
            InsuranceType expected = new InsuranceType{ Name = "Вид страховки 1"};
            target.InsuranceType = expected;
            InsuranceType actual = target.InsuranceType;
            Assert.AreEqual(expected, actual);
        }

    }
}
