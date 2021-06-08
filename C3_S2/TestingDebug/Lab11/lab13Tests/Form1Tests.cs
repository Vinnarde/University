using Microsoft.VisualStudio.TestTools.UnitTesting;
using lab13;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab13.Tests
{
    [TestClass()]
    public class Form1Tests
    {
        [TestMethod()]
        public void Form1Test()
        {
            var target = new Form1();
            Assert.IsInstanceOfType(target, typeof(Form1));
        }

    }
}