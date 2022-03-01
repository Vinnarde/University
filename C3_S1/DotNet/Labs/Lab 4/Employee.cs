namespace ClassLibraryWork
{
    internal interface IValid
    {
        bool IsValid { get; }
    } 

    // ------ Class - Employee ------ //
    public class Employee : IValid
    {
        // ---- Properties --- //

        /// <summary>
        ///     Firs tName of worker
        /// </summary>
        public string FirstName { get; set; } = "";

        /// <summary>
        ///     Last Name of worker
        /// </summary>
        public string LastName { get; set; } = "";

        /// <summary>
        ///     Patronymic of worker
        /// </summary>
        public string Patronymic { get; set; } = "";


        /// <summary>
        ///     Salary of worker
        /// </summary>
        public double Salary { get; set; }


        public bool IsValid
        {
            get
            {
                if (string.IsNullOrWhiteSpace(FirstName)) return false;
                if (string.IsNullOrWhiteSpace(Patronymic)) return false;
                if (string.IsNullOrWhiteSpace(LastName)) return false;
                return true;
            }
        }

        // --- Methods --- //

        /// <summary>
        ///     Default Constructor
        /// </summary>
        public Employee()
        {
        }


        /// <summary>
        ///     The full constructor
        /// </summary>
        public Employee(string firstName, string lastName, string patronymic, double salary)
        {
            FirstName = firstName;
            LastName = lastName;
            Patronymic = patronymic;
            Salary = salary;
        }

        public override string ToString()
        {
            return "First Name - " + FirstName + ", Last Name - " + LastName + ", Patronymic - " + Patronymic +
                   ".\r\nSalary = " + Salary + ".\r\n\n";
        }
    }

}
