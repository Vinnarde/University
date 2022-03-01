using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;

namespace Lab11.Models
{
    public class Degree
    {
        public int Id { get; set; }
        public string Title { get; set; }

        private static readonly string _selectDegreesQuery =
            @"SELECT [id], [title] FROM [degrees]";
        private static readonly string _insertDegreeQuery =
            @"INSERT INTO [degrees]  ([title]) VALUES (@Title)";
        private static readonly string _updateDegreeQuery =
            @"UPDATE [degrees] SET [title] = @Title WHERE [id] = @Id";
        private static readonly string _deleteDegreeQuery =
            @"DELETE FROM [degrees] WHERE [id] = @Id";

        public override string ToString()
        {
            return Title;
        }

        public static List<Degree> List(SqlConnection connection)
        {
            List<Degree> degrees = new List<Degree>();
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _selectDegreesQuery;
                    command.CommandType = CommandType.Text;
                    connection.Open();
                    var reader = command.ExecuteReader();
                    while (reader.Read())
                    {
                        Degree degree = new Degree
                        {
                            Id = (int)reader["id"],
                            Title = (string)reader["title"]
                        };
                        degrees.Add(degree);
                    }
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
            return degrees;
        }

        public static void Insert(SqlConnection connection, Degree degree)
        {
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _insertDegreeQuery;
                    command.CommandType = CommandType.Text;
                    command.Parameters.Add("@Title", SqlDbType.VarChar, 32).Value = degree.Title;
                    connection.Open();
                    command.ExecuteNonQuery();
                }
                finally
                {
                    if (connection != null && connection.State == ConnectionState.Open) connection.Close();
                }
            }
        }

        public static void Update(SqlConnection connection, Degree degree)
        {
            using (SqlCommand command = new SqlCommand())
            {
                try
                {
                    command.Connection = connection;
                    command.CommandText = _updateDegreeQuery;
                    command.CommandType = CommandType.Text;
                    command.Parameters.Add("@Id", SqlDbType.Int).Value = degree.Id;
                    command.Parameters.Add("@Title", SqlDbType.VarChar, 32).Value = degree.Title;
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
                    command.CommandText = _deleteDegreeQuery;
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
