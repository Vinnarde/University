
using System;
using System.Collections.Generic;
using System.Linq;

namespace PartsStore
{
    public class Store
    {
        private List<Provider> _providers = new List<Provider>();
        private List<Part> _parts = new List<Part>();
        private List<Supply> _supplies = new List<Supply>();

        public List<Provider> Providers
        {
            get { return _providers; }
            set { _providers = value; }
        }

        public List<Part> Parts
        {
            get { return _parts; }
            set { _parts = value; }
        }

        public List<Supply> Supplies
        {
            get { return _supplies; }
            set { _supplies = value; }
        }

        public Supply AddSupply (Provider provider, Part part, int number)
        {
            Supply supply = new Supply()
            {
                Provider = provider,
                Part = part,
                Number = number,
                Date = DateTime.Now
            };

            Supplies.Add(supply);

            return supply;
        }

        public Part AddPart (string title, int code, decimal price, string note)
        {
            Part part = new Part()
            {
                Title = title,
                Code = code,
                Price = price,
                Note = note
            };
            return part;
        }

        public Provider AddProvider (string title, string address, string phone)
        {
            Provider provider = new Provider()
            {
                Title = title,
                Address = address,
                Phone = phone
            };
            return provider;
        }

        public decimal GetSupplyTotal(Supply supply)
        {
            return supply.Number * supply.Part.Price;
        }

        public int GetTotalParts(Part part)
        {
            // посчитать, сколько всего поступало таких запчастей 
            return Supplies.Aggregate(0, (total, next) => 
                total += (next.Part == part) ? next.Number : 0
            );
        }

    }
}
