namespace ClassLibraryWork
{

    // ------ Class - Type of Work ------ //
    public class TypeOfWork : IValid
    {
        // ---- Properties --- ///

        /// <summary>
        ///     Payment per Day of worker
        /// </summary>
        public int PaymentPerDay { get; set; } = -1;

        /// <summary>
        ///     Description position of worker
        /// </summary>
        public string Description { get; set; } = "";

        public bool IsValid
        {
            get
            {
                if (PaymentPerDay == -1) return false;
                if (string.IsNullOrWhiteSpace(Description)) return false;
                return true;
            }
        }


        // --- Methods --- //

        /// <summary>
        ///     Default Constructor
        /// </summary>
        public TypeOfWork()
        {
        }

        /// <summary>
        ///     The full constructor
        /// </summary>
        public TypeOfWork(string description, int paymentPerDay)
        {
            Description = description;
            PaymentPerDay = paymentPerDay;
        }

        public override string ToString()
        {
            return "Payment per Day = " + PaymentPerDay + ".\r\n Description: " + Description + ".\r\n";
        }
    }

}
