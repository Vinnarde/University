using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Data.Entity.Infrastructure;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Description;
using Lab15;

namespace Lab15.Controllers
{
    public class TeachersController : ApiController
    {
        private DBEntities db = new DBEntities();

        // GET: api/Teachers
        public IQueryable<teacher> Getteachers()
        {
            return db.teachers;
        }

        // GET: api/Teachers/5
        [ResponseType(typeof(teacher))]
        public async Task<IHttpActionResult> Getteacher(int id)
        {
            teacher teacher = await db.teachers.FindAsync(id);
            if (teacher == null)
            {
                return NotFound();
            }

            return Ok(teacher);
        }

        // PUT: api/Teachers/5
        [ResponseType(typeof(void))]
        public async Task<IHttpActionResult> Putteacher(int id, teacher teacher)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            if (id != teacher.id)
            {
                return BadRequest();
            }

            db.Entry(teacher).State = EntityState.Modified;

            try
            {
                await db.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!teacherExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return StatusCode(HttpStatusCode.NoContent);
        }

        // POST: api/Teachers
        [ResponseType(typeof(teacher))]
        public async Task<IHttpActionResult> Postteacher(teacher teacher)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            db.teachers.Add(teacher);
            await db.SaveChangesAsync();

            return CreatedAtRoute("DefaultApi", new { id = teacher.id }, teacher);
        }

        // DELETE: api/Teachers/5
        [ResponseType(typeof(teacher))]
        public async Task<IHttpActionResult> Deleteteacher(int id)
        {
            teacher teacher = await db.teachers.FindAsync(id);
            if (teacher == null)
            {
                return NotFound();
            }

            db.teachers.Remove(teacher);
            await db.SaveChangesAsync();

            return Ok(teacher);
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }

        private bool teacherExists(int id)
        {
            return db.teachers.Count(e => e.id == id) > 0;
        }
    }
}