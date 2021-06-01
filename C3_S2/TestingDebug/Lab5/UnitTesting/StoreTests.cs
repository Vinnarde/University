using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace PartsStore.Tests
{
    [TestClass()]
    public class StoreTests
    {
        [TestMethod()]
        public void AddSupplyTest()
        {
            Store store = new Store();
            Part part = store.AddPart("Gear shift", 123123123, 666.66m, "Test note");
            Provider provider = store.AddProvider("My provider", "ulitsa kolotushkina", "800000000000");
            Supply expected = new Supply
            {
                Part = part,
                Provider = provider
            };
            store.AddSupply(provider, part, 123);

            Supply actual = store.Supplies.Find(s => s.Provider.Title == "My provider" && s.Part.Title == "Gear shift");

            Assert.IsNotNull(actual);
            Assert.IsNotNull(expected);
            Assert.AreEqual(actual.Part.Title, expected.Part.Title);
            Assert.AreEqual(actual.Provider.Title, expected.Provider.Title);
        }

        [TestMethod()]
        public void AddPartTest()
        {
            Store store = new Store();

            Part actual = store.AddPart("Gear shift", 123123123, 666.66m, "Test note");

            Part expected = new Part
            {
                Title = "Gear shift",
                Code = 123123123,
                Price = 666.66m,
                Note = "Test note"
            };

            Assert.IsNotNull(actual);
            Assert.IsNotNull(expected);
            Assert.AreEqual(actual.Title, expected.Title);
            Assert.AreEqual(actual.Price, expected.Price);
            Assert.AreEqual(actual.Code, expected.Code);
        }

        [TestMethod()]
        public void GetSupplyTotalTest()
        {

            Store store = new Store();

            Part part = store.AddPart("Gear shift", 123123123, 13.37m, "Test note");
            Provider provider = store.AddProvider("My provider", "ulitsa Pushkina", "800000000000");

            Supply actual = store.AddSupply(provider, part, 123);

            decimal total = store.GetSupplyTotal(actual);

            Assert.AreEqual(total, 123 * 13.37m);
        }

        [TestMethod()]
        public void GetTotalPartsTest()
        {
            Store store = new Store();

            Part part1 = store.AddPart("Gear shift", 123123123, 666.66m, "Test note");
            Part part2 = store.AddPart("Engine", 4582881, 111.66m, "Test note");
            Provider provider1 = store.AddProvider("My provider", "ulitsa Pushkina", "800000000000");
            Provider provider2 = store.AddProvider("My provider2", "address", "123123123111");

            store.AddSupply(provider1, part1, 67);
            store.AddSupply(provider2, part2, 55);
            store.AddSupply(provider1, part2, 123);

            int total = store.GetTotalParts(part2);

            Assert.AreEqual(total, 55 + 123);
        }
    }
}