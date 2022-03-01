using System.Data.Entity;
using System.Data.Entity.Infrastructure;
using System.Linq;
using System.Net;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Description;
using Lab15;

namespace Lab15.Controllers
{
    public class DegreesController : ApiController
    {
        private DBEntities db = new DBEntities();

        // GET: api/Degrees
        public IQueryable<degree> Getdegrees()
        {
            return db.degrees;
        }

        // GET: api/Degrees/5
        [ResponseType(typeof(degree))]
        public async Task<IHttpActionResult> Getdegree(int id)
        {
            degree degree = await db.degrees.FindAsync(id);
            if (degree == null)
            {
                return NotFound();
            }

            return Ok(degree);
        }

        // PUT: api/Degrees/5
        [ResponseType(typeof(void))]
        public async Task<IHttpActionResult> Putdegree(int id, degree degree)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            if (id != degree.id)
            {
                return BadRequest();
            }

            db.Entry(degree).State = EntityState.Modified;

            try
            {
                await db.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!degreeExists(id))
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

        // POST: api/Degrees
        [ResponseType(typeof(degree))]
        public async Task<IHttpActionResult> Postdegree(degree degree)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            db.degrees.Add(degree);
            await db.SaveChangesAsync();

            return CreatedAtRoute("DefaultApi", new { id = degree.id }, degree);
        }

        // DELETE: api/Degrees/5
        [ResponseType(typeof(degree))]
        public async Task<IHttpActionResult> Deletedegree(int id)
        {
            degree degree = await db.degrees.FindAsync(id);
            if (degree == null)
            {
                return NotFound();
            }

            db.degrees.Remove(degree);
            await db.SaveChangesAsync();

            return Ok(degree);
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }

        private bool degreeExists(int id)
        {
            return db.degrees.Count(e => e.id == id) > 0;
        }
    }
}