using Microsoft.VisualStudio.TestTools.UnitTesting;
using lab13;
using System;

namespace UnitTestProject
{
    [TestClass]
    public class Lab15Driver
    {
        [TestMethod]
        public void TestMethod1()
        {
            var types = Catalog.GetInsuranceTypes();
            var flag = Contracts.AddContract(System.DateTime.Today, 1000m, 1.0m, 1);
            var contract = Search.FindContracts(1);

            Assert.IsNotNull(types);
            Assert.IsTrue(flag);
            Assert.IsNotNull(contract);
        }

        [TestMethod]
        public void TestMethodMocks()
        {
            var types = CatalogMock.GetTypes();
            var flag = ContractMock.AddContract(System.DateTime.Today, 1000m, 1.0m, 1);
            var contract = SearchMock.FindContracts(1);

            Assert.IsNotNull(types);
            Assert.IsTrue(flag);
            Assert.IsNotNull(contract);
        }
    }
}
