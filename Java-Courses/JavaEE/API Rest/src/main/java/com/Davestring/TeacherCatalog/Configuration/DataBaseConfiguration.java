package com.Davestring.TeacherCatalog.Configuration;

import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.orm.hibernate5.HibernateTransactionManager;
import org.springframework.jdbc.datasource.DriverManagerDataSource;
import org.springframework.orm.hibernate5.LocalSessionFactoryBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Bean;
import java.util.Properties;
import javax.sql.DataSource;

@Configuration
@EnableTransactionManagement
public class DataBaseConfiguration {
	
	@Bean
	public LocalSessionFactoryBean sessionFactory ( ) {
		LocalSessionFactoryBean sessionFactoryBean = new LocalSessionFactoryBean ( );
		sessionFactoryBean.setDataSource ( dataSource ( ) );
		sessionFactoryBean.setPackagesToScan ( "com.Davestring.TeacherCatalog.Model" );
		sessionFactoryBean.setHibernateProperties ( hibernateProperties ( ) );
		return sessionFactoryBean;
	} // End method.
	
	@Bean
	public DataSource dataSource ( ) {
		DriverManagerDataSource dataSource = new DriverManagerDataSource ( );
		dataSource.setDriverClassName ( "com.mysql.jdbc.Driver" );
		dataSource.setUrl ( "jdbc:mysql://localhost/Courses" );
		dataSource.setUsername ( "root" );
		dataSource.setPassword ( "Davestring" );
		return dataSource;
	} // End method.
	
	public Properties hibernateProperties ( ) {
		Properties p = new Properties ( );
		p.put ( "hibernate.dialect", "org.hibernate.dialect.MySQLDialect");
		p.put ( "show_sql", "true" );
		return p;
	} // End method.
	
	@Bean
	@Autowired
	public HibernateTransactionManager transactionManager ( ) {
		HibernateTransactionManager hibernateTransactionManager = new HibernateTransactionManager ( );
		hibernateTransactionManager.setSessionFactory ( sessionFactory ( ).getObject ( ) );
		return hibernateTransactionManager;
	} // End method.
} // End class.
