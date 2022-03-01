using System.Collections.Generic;
using System.Web.Services;
using ClassLibraryData;
using ClassLibraryMethods;

namespace Lab17
{
    /// <summary>
    /// Web service for Lab 17
    /// </summary>
    [WebService(
        Name = "LAB 17",
        Description = "Web service for Lab 17"
    )]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    public class WebService : System.Web.Services.WebService
    {

        [WebMethod(Description = "Get a list of teachers")]
        public List<TeacherDTO> GetTeachers()
        {
            ServiceMethods methods = new ServiceMethods();
            return methods.GetTeachers();
        }

        [WebMethod(Description = "Get a list of scientific degrees")]
        public List<DegreeDTO> GetDegrees()
        {
            ServiceMethods methods = new ServiceMethods();
            return methods.GetDegrees();
        }

        [WebMethod(Description = "Add new scientific degree")]
        public void AddDegree(string title)
        {
            ServiceMethods methods = new ServiceMethods();
            methods.AddDegree(title);
        }

        [WebMethod(Description = "Delete a scientific degree")]
        public void RemoveDegree(int id_group)
        {
            ServiceMethods methods = new ServiceMethods();
            methods.DeleteDegree(id_group);
        }
    }
}
