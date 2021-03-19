using System;
using System.Collections.Generic;
using System.Text;
using Lab6;
using Microsoft.VisualStudio.TestTools.UnitTesting;
namespace Lab6Test
{
    [TestClass]
    public class PostTest
    {
        /// <summary>
        ///Получает или устанавливает контекст теста, в котором предоставляются
        ///сведения о текущем тестовом запуске и обеспечивается его функциональность.
        ///</summary>
        public TestContext TestContext { get; set; }


        /// <summary>
        /// Пустое слово
        ///</summary>
        [TestMethod]
        public void RatingTest1()
        {
            var target = new Post();
            const double expected = 0.0;
            target.Message = "";
            Assert.AreEqual(expected, target.CountRating());
        }

        /// <summary>
        /// Одно слово
        ///</summary>
        [TestMethod]
        public void RatingTest2()
        {
            var target = new Post();
            const double expected = 2.5;
            target.Message = "WorD";
            Assert.AreEqual(expected, target.CountRating());
        }

        /// <summary>
        /// Два слова через пробел(' ')
        ///</summary>
        [TestMethod]
        public void RatingTest3()
        {
            var target = new Post();
            const double expected = 5.0;
            target.Message = "WorD Word";
            Assert.AreEqual(expected, target.CountRating());
        }

        /// <summary>
        /// Два слова через TAB(',')
        ///</summary>
        [TestMethod]
        public void RatingTest4()
        {
            var target = new Post();
            const double expected = 5.0;
            target.Message = "WorD,Word";
            Assert.AreEqual(expected, target.CountRating());
        }

        /// <summary>
        /// Одно слово с точкой на конце
        ///</summary>
        [TestMethod]
        public void RatingTest5()
        {
            var target = new Post();
            const double expected = 2.5;
            target.Message = "WorD.";
            Assert.AreEqual(expected, target.CountRating());
        }
        /// <summary>
        /// Три одинаковых слова
        ///</summary>
        [TestMethod]
        public void RatingTest6()
        {
            var target = new Post();
            const double expected = 2.0;
            target.Message = "a a, a";
            Assert.AreEqual(expected, target.CountRating());
        }

    }
}
