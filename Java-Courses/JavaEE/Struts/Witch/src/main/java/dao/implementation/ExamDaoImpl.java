package dao.implementation;

import database.ConnectorManager;
import java.util.ArrayList;
import dao.ExamDao;
import models.Exam;

public class ExamDaoImpl implements ExamDao {

	private ConnectorManager conn = new ConnectorManager();
	
	public void create(Exam exam) {
		conn.getSession().persist(exam);
		conn.getSession().getTransaction().commit();
	}

	public void update(Exam exam) {
		conn.getSession().update(exam);
		conn.getSession().getTransaction().commit();
	}

	public void delete(Integer id) {
		conn.getSession().delete(conn.getSession().get(Exam.class, id));
		conn.getSession().getTransaction().commit();
	}

	public Exam findById(Integer id) {
		try {
			String query = "FROM Exam WHERE id = '" + id.toString() + "'";
			return (Exam) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}
	
	public Exam findByName(String name) {
		try {
			String query = "FROM Exam WHERE name = '" + name + "'";
			return (Exam) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}
	
	public Exam findByDate(String date) {
		try {
			String query = "FROM Exam WHERE date = '" + date + "'";
			return (Exam) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}

	@SuppressWarnings("unchecked")
	public ArrayList<Exam> findAll() {
		return (ArrayList<Exam>) conn.getSession().createQuery("FROM Exam").list();
	}

}
