using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;

namespace Lab11.Models
{
    public class Teacher
    {
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string MiddleName { get; set; }
        public int Degree { get; set; }
        public string DegreeTitle { get; set; }

        private static readonly string _selectTeachersQuery =
            @"SELECT teachers.id, first_name, last_name, middle_name, degree, degrees.title AS degree_title
                FROM teachers JOIN degrees 
                ON (teachers.degree = degrees.id)";
        private static readonly string _insertTeacherQuery =
            @"INSERT INTO [dbo].[Teachers] 
                ([first_name], [last_name], [middle_name], [degree]) 
                VALUES (@FirstName, @LastName, @MiddleName, @Degree)";
        private static readonly string _updateTeacherQuery =
            @"UPDATE [dbo].[Teachers] SET
                [first_name] = @FirstName,
                [last_name] = @LastName,
                [middle_name] = @MiddleName,
                [degree] = @Degree
            WHERE [id] = @Id";
        private static readonly string _deleteTeacherQuery =
            @"DELETE FROM [dbo].[Teachers] 
            WHERE [id] = @Id";


        public static List<Teacher> List(SqlConnection connection)
        {
            List<Teacher> teachers = new List<Teacher>();
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _selectTeachersQuery;
                    command.CommandType = CommandType.Text;
                    connection.Open();
                    var reader = command.ExecuteReader();
                    while (reader.Read())
                    {
                        Teacher teacher = new Teacher
                        {
                            Id = (int) reader["id"],
                            FirstName = (string) reader["first_name"],
                            MiddleName = (string) reader["middle_name"],
                            LastName = (string) reader["last_name"],
                            Degree = (int) reader["degree"],
                            DegreeTitle = (string) reader["degree_title"]
                        };
                        teachers.Add(teacher);
                    }
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
            return teachers;
        }

        public static void Insert(SqlConnection connection, Teacher teacher)
        {
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _insertTeacherQuery;
                    command.CommandType = CommandType.Text;
                    command.Parameters.Add("@FirstName", SqlDbType.VarChar, 32).Value = teacher.FirstName;
                    command.Parameters.Add("@LastName", SqlDbType.VarChar, 32).Value = teacher.LastName;
                    command.Parameters.Add("@MiddleName", SqlDbType.VarChar, 32).Value = teacher.MiddleName;
                    command.Parameters.Add("@Degree", SqlDbType.Int, 32).Value = teacher.Degree;
                    connection.Open();
                    command.ExecuteNonQuery();
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
        }

        public static void Update(SqlConnection connection, Teacher teacher)
        {
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _updateTeacherQuery;
                    command.CommandType = CommandType.Text;
                    command.Parameters.Add("@Id", SqlDbType.Int).Value = teacher.Id;
                    command.Parameters.Add("@FirstName", SqlDbType.VarChar, 32).Value = teacher.FirstName;
                    command.Parameters.Add("@LastName", SqlDbType.VarChar, 32).Value = teacher.LastName;
                    command.Parameters.Add("@MiddleName", SqlDbType.VarChar, 32).Value = teacher.MiddleName;
                    command.Parameters.Add("@Degree", SqlDbType.VarChar, 32).Value = teacher.Degree;
                    connection.Open();
                    command.ExecuteNonQuery();
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
        }

        public static void Delete(SqlConnection connection, int id)
        {
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _deleteTeacherQuery;
                    command.CommandType = CommandType.Text;
                    command.Parameters.Add("@Id", SqlDbType.Int).Value = id;
                    connection.Open();
                    command.ExecuteNonQuery();
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
        }

    }
}
