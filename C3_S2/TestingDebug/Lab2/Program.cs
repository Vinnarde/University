using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]

        //#region GetFirstFactorParallel(decimal Num) algorithm
        ///// <summary>
        ///// ===================================================================
        ///// Copyright(C)2012-2015 Alexander Bell
        ///// ===================================================================
        ///// parallel algorithm accepts decimal Num 
        ///// and returns either first found not-trivial factor, or number 1.
        ///// This algo provides performance boost 
        ///// in comparison to serial implementation on prime factoring of
        ///// big prime numbers
        ///// </summary>
        ///// <param name="Num">decimal</param>
        ///// <returns>decimal</returns>
        //static decimal GetFirstFactorParallel(decimal Num)
        //{
        //    // use concurrent stack to store non-trivial factor if found
        //    ConcurrentStack<decimal> _stack = new ConcurrentStack<decimal>();

        //    // object to specify degrees of parallelism
        //    ParallelOptions _po = new ParallelOptions();

        //    try
        //    {
        //        // return value initially set to 1
        //        decimal _ret = 1;

        //        // step 1: try to factor on base 2, return if OK
        //        if (Num % 2 == 0) return 2;

        //        // step 2: try to factor on base 3, return if OK
        //        if (Num % 3 == 0) return 3;

        //        #region parallel algo to find first non-trivial factor if exists

        //        // set upper limit
        //        decimal _upMargin = (decimal)Math.Sqrt((double)Num) + 1;

        //        // number of CPU cores
        //        int _countCPU = System.Environment.ProcessorCount;

        //        // max degree of parallelism set equal to _cpuCount
        //        _po.MaxDegreeOfParallelism = _countCPU;

        //        Parallel.For(0, 2, _po, (i, _plState) =>
        //        {
        //            // starting number for inner loops (5 and 7)
        //            int _seed = 5 + 2 * i;

        //            // inner loops running in parallel;
        //            // notice that because input Num was already tested for factors 2 and 3,
        //            // then increment of 6 is used to speed up the processing,
        //            // thus in dual core CPU it looks like:
        //            // 5, 11, 17, 23, 29, etc. in first thread
        //            // 7, 13, 19, 25, 31, etc, in second thread
        //            for (decimal j = _seed; j < _upMargin; j += 6)
        //            {
        //                // exit loop if stack contains value
        //                if (_stack.Count != 0) { break; }

        //                // check divisibility
        //                if (Num % j == 0)
        //                {
        //                    // push non-trivial factor to ConcurrentStack and exit loop
        //                    if (_stack.Count == 0) { _stack.Push(j); }
        //                    break;
        //                }
        //            }
        //        });
        //        #endregion

        //        // return the value in ConcurrentStack if exists, or 1
        //        return (_stack.TryPop(out _ret)) ? _ret : 1;
        //    }
        //    catch { throw; }
        //    finally { _po = null; _stack = null; }

        //}
        //#endregion
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            
        }
    }
}
