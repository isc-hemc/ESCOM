package com.Davestring.TeacherCatalog.DAO;

import com.Davestring.TeacherCatalog.Model.TeacherSocialMedia;
import com.Davestring.TeacherCatalog.Model.SocialMedia;
import java.util.List;

public interface SocialMediaDao {

	void createSocialMedia ( SocialMedia socialMedia );
	
	void updateSocialMedia ( SocialMedia socialMedia );
	
	void deleteSocialMedia ( Long idSocialMedia );
	
	SocialMedia findById ( Long idSocialMedia );
	
	SocialMedia findByName ( String name );
	
	List <SocialMedia> findAllSocialMedia ( );
	
	TeacherSocialMedia findByIdAndNickname ( Long idSocialMedia, String nickname );
	
} // End interface.
