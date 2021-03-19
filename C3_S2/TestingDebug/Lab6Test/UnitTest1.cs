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
        ///�������� ��� ������������� �������� �����, � ������� ���������������
        ///�������� � ������� �������� ������� � �������������� ��� ����������������.
        ///</summary>
        public TestContext TestContext { get; set; }


        /// <summary>
        /// ������ �����
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
        /// ���� �����
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
        /// ��� ����� ����� ������(' ')
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
        /// ��� ����� ����� TAB(',')
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
        /// ���� ����� � ������ �� �����
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
        /// ��� ���������� �����
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
