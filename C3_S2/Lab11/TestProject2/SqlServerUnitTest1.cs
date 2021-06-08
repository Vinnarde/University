using Microsoft.Data.Tools.Schema.Sql.UnitTesting;
using Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Text;

namespace TestProject2
{
    [TestClass()]
    public class SqlServerUnitTest1 : SqlDatabaseTestClass
    {

        public SqlServerUnitTest1()
        {
            InitializeComponent();
        }

        [TestInitialize()]
        public void TestInitialize()
        {
            base.InitializeTest();
        }
        [TestCleanup()]
        public void TestCleanup()
        {
            base.CleanupTest();
        }

        #region Designer support code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction dbo_Procedure1Test_TestAction;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SqlServerUnitTest1));
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.InconclusiveCondition inconclusiveCondition1;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction dbo_Procedure1Test_PretestAction;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction ContractTypeJoin_TestAction;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition expectedSchemaCondition1;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction Contracts_TestAction;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition expectedSchemaCondition2;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction InsuranceType_TestAction;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition expectedSchemaCondition3;
            Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ScalarValueCondition scalarValueCondition1;
            this.dbo_Procedure1TestData = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestActions();
            this.ContractTypeJoinData = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestActions();
            this.ContractsData = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestActions();
            this.InsuranceTypeData = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestActions();
            dbo_Procedure1Test_TestAction = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction();
            inconclusiveCondition1 = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.InconclusiveCondition();
            dbo_Procedure1Test_PretestAction = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction();
            ContractTypeJoin_TestAction = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction();
            expectedSchemaCondition1 = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition();
            Contracts_TestAction = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction();
            expectedSchemaCondition2 = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition();
            InsuranceType_TestAction = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.SqlDatabaseTestAction();
            expectedSchemaCondition3 = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ExpectedSchemaCondition();
            scalarValueCondition1 = new Microsoft.Data.Tools.Schema.Sql.UnitTesting.Conditions.ScalarValueCondition();
            // 
            // dbo_Procedure1Test_TestAction
            // 
            dbo_Procedure1Test_TestAction.Conditions.Add(inconclusiveCondition1);
            resources.ApplyResources(dbo_Procedure1Test_TestAction, "dbo_Procedure1Test_TestAction");
            // 
            // inconclusiveCondition1
            // 
            inconclusiveCondition1.Enabled = true;
            inconclusiveCondition1.Name = "inconclusiveCondition1";
            // 
            // dbo_Procedure1Test_PretestAction
            // 
            resources.ApplyResources(dbo_Procedure1Test_PretestAction, "dbo_Procedure1Test_PretestAction");
            // 
            // ContractTypeJoin_TestAction
            // 
            ContractTypeJoin_TestAction.Conditions.Add(expectedSchemaCondition1);
            resources.ApplyResources(ContractTypeJoin_TestAction, "ContractTypeJoin_TestAction");
            // 
            // expectedSchemaCondition1
            // 
            expectedSchemaCondition1.Enabled = true;
            expectedSchemaCondition1.Name = "expectedSchemaCondition1";
            resources.ApplyResources(expectedSchemaCondition1, "expectedSchemaCondition1");
            expectedSchemaCondition1.Verbose = false;
            // 
            // Contracts_TestAction
            // 
            Contracts_TestAction.Conditions.Add(expectedSchemaCondition2);
            Contracts_TestAction.Conditions.Add(scalarValueCondition1);
            resources.ApplyResources(Contracts_TestAction, "Contracts_TestAction");
            // 
            // expectedSchemaCondition2
            // 
            expectedSchemaCondition2.Enabled = true;
            expectedSchemaCondition2.Name = "expectedSchemaCondition2";
            resources.ApplyResources(expectedSchemaCondition2, "expectedSchemaCondition2");
            expectedSchemaCondition2.Verbose = false;
            // 
            // InsuranceType_TestAction
            // 
            InsuranceType_TestAction.Conditions.Add(expectedSchemaCondition3);
            resources.ApplyResources(InsuranceType_TestAction, "InsuranceType_TestAction");
            // 
            // expectedSchemaCondition3
            // 
            expectedSchemaCondition3.Enabled = true;
            expectedSchemaCondition3.Name = "expectedSchemaCondition3";
            resources.ApplyResources(expectedSchemaCondition3, "expectedSchemaCondition3");
            expectedSchemaCondition3.Verbose = false;
            // 
            // dbo_Procedure1TestData
            // 
            this.dbo_Procedure1TestData.PosttestAction = null;
            this.dbo_Procedure1TestData.PretestAction = dbo_Procedure1Test_PretestAction;
            this.dbo_Procedure1TestData.TestAction = dbo_Procedure1Test_TestAction;
            // 
            // ContractTypeJoinData
            // 
            this.ContractTypeJoinData.PosttestAction = null;
            this.ContractTypeJoinData.PretestAction = null;
            this.ContractTypeJoinData.TestAction = ContractTypeJoin_TestAction;
            // 
            // ContractsData
            // 
            this.ContractsData.PosttestAction = null;
            this.ContractsData.PretestAction = null;
            this.ContractsData.TestAction = Contracts_TestAction;
            // 
            // InsuranceTypeData
            // 
            this.InsuranceTypeData.PosttestAction = null;
            this.InsuranceTypeData.PretestAction = null;
            this.InsuranceTypeData.TestAction = InsuranceType_TestAction;
            // 
            // scalarValueCondition1
            // 
            scalarValueCondition1.ColumnNumber = 1;
            scalarValueCondition1.Enabled = true;
            scalarValueCondition1.ExpectedValue = "3";
            scalarValueCondition1.Name = "scalarValueCondition1";
            scalarValueCondition1.NullExpected = false;
            scalarValueCondition1.ResultSet = 1;
            scalarValueCondition1.RowNumber = 1;
        }

        #endregion


        #region Additional test attributes
        //
        // You can use the following additional attributes as you write your tests:
        //
        // Use ClassInitialize to run code before running the first test in the class
        // [ClassInitialize()]
        // public static void MyClassInitialize(TestContext testContext) { }
        //
        // Use ClassCleanup to run code after all tests in a class have run
        // [ClassCleanup()]
        // public static void MyClassCleanup() { }
        //
        #endregion

        [TestMethod()]
        public void dbo_Procedure1Test()
        {
            SqlDatabaseTestActions testActions = this.dbo_Procedure1TestData;
            // Execute the pre-test script
            // 
            System.Diagnostics.Trace.WriteLineIf((testActions.PretestAction != null), "Executing pre-test script...");
            SqlExecutionResult[] pretestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PretestAction);
            try
            {
                // Execute the test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.TestAction != null), "Executing test script...");
                SqlExecutionResult[] testResults = TestService.Execute(this.ExecutionContext, this.PrivilegedContext, testActions.TestAction);
            }
            finally
            {
                // Execute the post-test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.PosttestAction != null), "Executing post-test script...");
                SqlExecutionResult[] posttestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PosttestAction);
            }
        }
        [TestMethod()]
        public void ContractTypeJoin()
        {
            SqlDatabaseTestActions testActions = this.ContractTypeJoinData;
            // Execute the pre-test script
            // 
            System.Diagnostics.Trace.WriteLineIf((testActions.PretestAction != null), "Executing pre-test script...");
            SqlExecutionResult[] pretestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PretestAction);
            try
            {
                // Execute the test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.TestAction != null), "Executing test script...");
                SqlExecutionResult[] testResults = TestService.Execute(this.ExecutionContext, this.PrivilegedContext, testActions.TestAction);
            }
            finally
            {
                // Execute the post-test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.PosttestAction != null), "Executing post-test script...");
                SqlExecutionResult[] posttestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PosttestAction);
            }
        }
        [TestMethod()]
        public void Contracts()
        {
            SqlDatabaseTestActions testActions = this.ContractsData;
            // Execute the pre-test script
            // 
            System.Diagnostics.Trace.WriteLineIf((testActions.PretestAction != null), "Executing pre-test script...");
            SqlExecutionResult[] pretestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PretestAction);
            try
            {
                // Execute the test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.TestAction != null), "Executing test script...");
                SqlExecutionResult[] testResults = TestService.Execute(this.ExecutionContext, this.PrivilegedContext, testActions.TestAction);
            }
            finally
            {
                // Execute the post-test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.PosttestAction != null), "Executing post-test script...");
                SqlExecutionResult[] posttestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PosttestAction);
            }
        }
        [TestMethod()]
        public void InsuranceType()
        {
            SqlDatabaseTestActions testActions = this.InsuranceTypeData;
            // Execute the pre-test script
            // 
            System.Diagnostics.Trace.WriteLineIf((testActions.PretestAction != null), "Executing pre-test script...");
            SqlExecutionResult[] pretestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PretestAction);
            try
            {
                // Execute the test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.TestAction != null), "Executing test script...");
                SqlExecutionResult[] testResults = TestService.Execute(this.ExecutionContext, this.PrivilegedContext, testActions.TestAction);
            }
            finally
            {
                // Execute the post-test script
                // 
                System.Diagnostics.Trace.WriteLineIf((testActions.PosttestAction != null), "Executing post-test script...");
                SqlExecutionResult[] posttestResults = TestService.Execute(this.PrivilegedContext, this.PrivilegedContext, testActions.PosttestAction);
            }
        }



        private SqlDatabaseTestActions dbo_Procedure1TestData;
        private SqlDatabaseTestActions ContractTypeJoinData;
        private SqlDatabaseTestActions ContractsData;
        private SqlDatabaseTestActions InsuranceTypeData;
    }
}
