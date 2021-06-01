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
    public class InsuranceTypeTest
    {
        /// <summary>
        ///Получает или устанавливает контекст теста, в котором предоставляются
        ///сведения о текущем тестовом запуске и обеспечивается его функциональность.
        ///</summary>
        public TestContext TestContext { get; set; }

        /// <summary>
        ///Тест для Конструктор InsuranceType
        ///</summary>
        [TestMethod]
        public void InsuranceTypeConstructorTest()
        {
            var target = new InsuranceType();
            Assert.IsInstanceOfType(target, typeof(InsuranceType));
        }

        /// <summary>
        ///Тест для Name
        ///</summary>
        [TestMethod]
        public void InsuranceTypeContractNameTest()
        {
            var target = new InsuranceType();
            const string expected = "Какой-то тип страховки";
            target.Name = expected;
            string actual = target.Name;
            Assert.AreEqual(expected, actual);
        }

    }
}
