using System.Collections.Generic;
using System.Linq;
using ClassLibraryData;

namespace ClassLibraryMethods
{
    public class ServiceMethods
    {
        public List<TeacherDTO> GetTeachers()
        {
            List<TeacherDTO> teachers = new List<TeacherDTO>();
            var dataset = new DBDataSet();
            var teachersAdapter = new ClassLibraryData.DBDataSetTableAdapters.teachersTableAdapter();
            teachersAdapter.Fill(dataset.teachers);
            var degreesAdapter = new ClassLibraryData.DBDataSetTableAdapters.degreesTableAdapter();
            degreesAdapter.Fill(dataset.degrees);
            
            teachers = (from item in dataset.teachers
                     select new TeacherDTO()
                     {
                         FirstName = item.first_name,
                         MiddleName = item.middle_name,
                         LastName = item.last_name,
                         DegreeId = item.degree,
                         DegreeTitle = item.degreesRow.title
                     }).ToList();

            return teachers;
        }

        public List<DegreeDTO> GetDegrees()
        {
            List<DegreeDTO> degrees = new List<DegreeDTO>();
            var dataset = new DBDataSet();
            var degreesAdapter = new ClassLibraryData.DBDataSetTableAdapters.degreesTableAdapter();
            degreesAdapter.Fill(dataset.degrees);

            degrees = (from item in dataset.degrees
                        select new DegreeDTO()
                        {
                            Id = item.id,
                            Title = item.title
                        }).ToList();

            return degrees;
        }

        public void AddDegree(string title)
        {
            var dataset = new DBDataSet();
            var degreesAdapter = new ClassLibraryData.DBDataSetTableAdapters.degreesTableAdapter();
            degreesAdapter.Fill(dataset.degrees);
            degreesAdapter.Insert(title);
        }

        public void DeleteDegree(int id)
        {
            var dataset = new DBDataSet();
            var degreesAdapter = new ClassLibraryData.DBDataSetTableAdapters.degreesTableAdapter();
            degreesAdapter.Fill(dataset.degrees);
            degreesAdapter.DeleteQuery(id);
        }

    }
}
