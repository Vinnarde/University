using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Data.Entity.Validation;
using System.IO;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Lab14.Models;

namespace Lab14.Controllers
{
    public class TeachersController : Controller
    {
        private DBEntities db = new DBEntities();

        // GET: Teachers
        public ActionResult Index()
        {
            var teachers = db.teachers.Include(t => t.degree1);
            return View(teachers.ToList());
        }

        // GET: Teachers/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            teacher teacher = db.teachers.Find(id);
            if (teacher == null)
            {
                return HttpNotFound();
            }
            return View(teacher);
        }

        // GET: Teachers/Create
        public ActionResult Create()
        {
            ViewBag.degree = new SelectList(db.degrees, "id", "title");
            return View();
        }

        // POST: Teachers/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "id,firstName,lastName,middleName,degree,photo")] teacher teacher)
        {
            using (var ms = new MemoryStream())
            {
                HttpPostedFileBase photoFile = Request.Files["PhotoFile"];
                if (photoFile != null && photoFile.ContentLength != 0)
                {
                    photoFile.InputStream.CopyTo(ms);
                    teacher.photo = ms.ToArray();
                }
            }

            if (ModelState.IsValid)
            {
                db.teachers.Add(teacher);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            ViewBag.degree = new SelectList(db.degrees, "id", "title", teacher.degree);
            return View(teacher);
        }

        // GET: Teachers/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            teacher teacher = db.teachers.Find(id);
            if (teacher == null)
            {
                return HttpNotFound();
            }
            ViewBag.degree = new SelectList(db.degrees, "id", "title", teacher.degree);
            return View(teacher);
        }

        // POST: Teachers/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit(
            [Bind(Include = "id,firstName,lastName,middleName,degree")] teacher teacher)
        {
            
            using (var ms = new MemoryStream())
            {
                HttpPostedFileBase photoFile = Request.Files["PhotoFile"];
                if (photoFile != null && photoFile.ContentLength != 0)
                {
                    photoFile.InputStream.CopyTo(ms);
                    teacher.photo = ms.ToArray();
                }
            }
            
            if (ModelState.IsValid)
            {
                db.Entry(teacher).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");

            }
            ViewBag.degree = new SelectList(db.degrees, "id", "title", teacher.degree);
            return View(teacher);
        }

        // GET: Teachers/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            teacher teacher = db.teachers.Find(id);
            if (teacher == null)
            {
                return HttpNotFound();
            }
            return View(teacher);
        }

        // POST: Teachers/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            teacher teacher = db.teachers.Find(id);
            db.teachers.Remove(teacher);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult GetImage(int id)
        {
            teacher teacher = db.teachers.Find(id);
            try
            {
                return File(teacher.photo, "image/jpeg");
            }
            catch (Exception)
            {
                return null;
            }
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
