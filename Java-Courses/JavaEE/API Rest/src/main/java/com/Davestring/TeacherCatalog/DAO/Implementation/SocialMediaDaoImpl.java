package com.Davestring.TeacherCatalog.DAO.Implementation;

import com.Davestring.TeacherCatalog.DAO.AbstractSession;
import com.Davestring.TeacherCatalog.DAO.SocialMediaDao;
import com.Davestring.TeacherCatalog.Model.SocialMedia;
import com.Davestring.TeacherCatalog.Model.TeacherSocialMedia;

import java.util.List;

public class SocialMediaDaoImpl extends AbstractSession implements SocialMediaDao {

	@Override
	public void createSocialMedia ( SocialMedia socialMedia ) {
		getSession ( ).persist ( socialMedia );
	} // End method.

	@Override
	public void updateSocialMedia ( SocialMedia socialMedia ) {
		getSession ( ).update ( socialMedia );
	} // End method.

	@Override
	public void deleteSocialMedia ( Long idSocialMedia ) {
		SocialMedia socialMedia = findById ( idSocialMedia );
		if ( socialMedia != null ) {
			getSession ( ).delete ( socialMedia );
		} // End if.
	} // End method.

	@Override
	public SocialMedia findById ( Long idSocialMedia ) {
		return ( SocialMedia ) getSession ( ).get ( SocialMedia.class, idSocialMedia );
	} // End method.

	@Override
	public SocialMedia findByName ( String name ) {
		return ( SocialMedia ) getSession ( ).createQuery ( 
					"FROM SocialMedia WHERE name = :name" )
					.setParameter ( "name", name ).uniqueResult ( );
	} // End method.

	@Override
	public List <SocialMedia> findAllSocialMedia ( ) {
		return getSession ( ).createQuery ( "FROM SocialMedia" ).list ( );
	} // End method.

	@Override
	public TeacherSocialMedia findByIdAndNickname ( Long idSocialMedia, String nickname ) {
		List <Object [ ]> object = getSession ( ).createQuery ( 
				"FROM TeacherSocialMedia tsm JOIN tsm.socialMedia sm WHERE sm.idSocialMedia = "
				+ ":idSocialMedia AND tsm.nickname = :nickname" )
				.setParameter ( "idSocialMedia", idSocialMedia )
				.setParameter ( "nickname", nickname ).list ( );
		
		if ( object.size ( ) > 0 ) {
			for ( Object [ ] object1 : object ) {
				for ( Object object2 : object1 ) {
					if ( object2 instanceof TeacherSocialMedia ) {
						return ( TeacherSocialMedia ) object2;
					} // End if.
				} // End nested for - each.
			} // End for - each.
		} // End if - else.
		
		return null;
	} // End method.
	
} // End class.
