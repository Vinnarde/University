using System;

namespace ClassLibraryWork
{
    // ------ Class - Job ------ //
    public class Job : IValid
    {
        // ---- Properties --- ///

        /// <summary>
        ///     information about worker
        /// </summary>
        public Employee Worker;

        /// <summary>
        ///     information about position of worker
        /// </summary>
        public TypeOfWork Position;

        /// <summary>
        ///     Start date work
        /// </summary>
        public DateTime StartDate { get; set; } = DateTime.MinValue;

        /// <summary>
        ///     End Date work
        /// </summary>
        public DateTime EndDate { get; set; } = DateTime.MinValue;

        public bool IsValid
        {
            get
            {
                if (StartDate == DateTime.MinValue) return false;
                if (EndDate == DateTime.MinValue) return false;
                return true;
            }
        }


        // --- Methods --- //
        /// <summary>
        ///     Default Constructor
        /// </summary>
        public Job()
        {
        }

        /// <summary>
        ///     The full constructor
        /// </summary>
        public Job(Employee worker, TypeOfWork position, DateTime startDate, DateTime endDate)
        {
            Worker = worker;
            Position = position;
            StartDate = startDate;
            EndDate = endDate;
        }

        public override string ToString()
        {
            return "Worker: " + Worker.FirstName + " " + Worker.LastName + " " + Worker.Patronymic + ".\r\n" +
                   "Position - " + Position.Description + ".\r\n" +
                   "Date: " + StartDate + " - " + EndDate + ".\r\n";
        }
    }
}
