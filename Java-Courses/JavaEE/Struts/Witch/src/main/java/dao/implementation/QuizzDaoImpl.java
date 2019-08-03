package dao.implementation;

import database.ConnectorManager;
import java.util.ArrayList;
import dao.QuizzDao;
import models.Quizz;

public class QuizzDaoImpl implements QuizzDao {

	private ConnectorManager conn = new ConnectorManager();
	
	public void create(Quizz quizz) {
		conn.getSession().persist(quizz);
		conn.getSession().getTransaction().commit();
	}

	public void update(Quizz quizz) {
		conn.getSession().update(quizz);
		conn.getSession().getTransaction().commit();
	}

	public void delete(Integer id) {
		// TODO Auto-generated method stub
		conn.getSession().delete(conn.getSession().get(Quizz.class, id));
		conn.getSession().getTransaction().commit();
	}

	public Quizz findById(Integer id) {
		try {
			String query = "FROM Quizz WHERE id = '" + id.toString() + "'";
			return (Quizz) conn.getSession().createQuery(query).uniqueResult();
		} catch(Exception e) {
			return null;
		}
	}
	
	@SuppressWarnings("unchecked")
	public ArrayList<Quizz> findByExamId(Integer id) {
		return (ArrayList<Quizz>) conn.getSession().createQuery("FROM Quizz WHERE idExam = '" + id.toString() + "'").list();
	}

	@SuppressWarnings("unchecked")
	public ArrayList<Quizz> findAll() {
		return (ArrayList<Quizz>) conn.getSession().createQuery("FROM Quizz").list();
	}

}
