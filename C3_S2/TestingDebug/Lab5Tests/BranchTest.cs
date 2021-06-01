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
    public class BranchTest
    {
        /// <summary>
        ///Получает или устанавливает контекст теста, в котором предоставляются
        ///сведения о текущем тестовом запуске и обеспечивается его функциональность.
        ///</summary>
        public TestContext TestContext { get; set; }

        /// <summary>
        ///Тест для Конструктор Branch
        ///</summary>
        [TestMethod]
        public void BranchConstructorTest()
        {
            var target = new Branch();
            Assert.IsInstanceOfType(target, typeof(Branch));
        }

        /// <summary>
        ///Тест для Name
        ///</summary>
        [TestMethod]
        public void BranchNameTest()
        {
            var target = new Branch();
            const string expected = "Филиал 1";
            target.Name = expected;
            string actual = target.Name;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для Address
        ///</summary>
        [TestMethod]
        public void BranchAddressTest()
        {
            var target = new Branch();
            const string expected = "Ул. Пушкина д.10 кв.123";
            target.Address = expected;
            string actual = target.Address;
            Assert.AreEqual(expected, actual);
        }

        /// <summary>
        ///Тест для Phone
        ///</summary>
        [TestMethod]
        public void BranchPhoneTest()
        {
            var target = new Branch();
            const string expected = "8-800-555-35-35";
            target.Phone = expected;
            string actual = target.Phone;
            Assert.AreEqual(expected, actual);
        }
    }
}
