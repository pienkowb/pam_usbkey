#define	PAM_SM_AUTH

#include "serial.h"

#include <security/pam_modules.h>
#include <security/pam_appl.h>

#include <stdio.h>

PAM_EXTERN int
pam_sm_authenticate(pam_handle_t* pamh, int flags, int argc, const char** argv)
{
	const char* user;
	int result;

	if((result = pam_get_user(pamh, &user, NULL)) != PAM_SUCCESS)
		return result;

	char serial[256] = {0};

	if(get_serial(user, serial, 255) == 0)
		if(check_serial(serial))
			return PAM_SUCCESS;

	return PAM_AUTH_ERR;
}

PAM_EXTERN int
pam_sm_setcred(pam_handle_t* pamh, int flags, int argc, const char** argv)
{
	return PAM_SUCCESS;
}

#ifdef PAM_MODULE_ENTRY
PAM_MODULE_ENTRY("pam_usbkey");
#endif
