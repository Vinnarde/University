using System.Web.Mvc;

namespace Lab15.Controllers
{
    public class Lab16Controller : Controller
    {
        // GET: Lab16
        //public ActionResult Index()
        //{
        //    ViewBag.Title = "smth";
        //    return View(); 
        //}

        public ActionResult Teachers()
        {
            ViewBag.Title = "Teachers";
            return View();
        }

        public ActionResult Degrees()
        {
            ViewBag.Title = "Degrees";
            return View();
        }
    }
}