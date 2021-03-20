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
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }

        /// <summary>
        /// ���� �����
        ///</summary>
        [TestMethod]
        public void RatingTest2()
        {
            var target = new Post();
            const double expected = 1.90;
            target.Message = "WorD";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }

        /// <summary>
        /// ��� ����� ����� ������(' ')
        ///</summary>
        [TestMethod]
        public void RatingTest3()
        {
            var target = new Post();
            const double expected = 3.8;
            target.Message = "WorD Word";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);

        }

        /// <summary>
        /// ��� ����� ����� �������(',')
        ///</summary>
        [TestMethod]
        public void RatingTest4()
        {
            var target = new Post();
            const double expected = 3.8;
            target.Message = "WorD,Word";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }

        /// <summary>
        /// ���� ����� � ������ �� �����
        ///</summary>
        [TestMethod]
        public void RatingTest5()
        {
            var target = new Post();
            const double expected = 5.3;
            target.Message = "self-confident";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }
        /// <summary>
        /// ��� ���������� �����
        ///</summary>
        [TestMethod]
        public void RatingTest6()
        {
            var target = new Post();
            const double expected = 1.6;
            target.Message = "a a, a";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }

        /// <summary>
        /// ��� ����� ����� '?'
        ///</summary>
        [TestMethod]
        public void RatingTest7()
        {
            var target = new Post();
            const double expected = 4.1;
            target.Message = "Pepega?YES?!";
            Assert.IsTrue(Math.Abs(expected - target.CountRating()) < 1e-5);
        }

    }
}
