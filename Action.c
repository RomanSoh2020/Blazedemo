Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("blazedemo.com", 
		"URL=https://blazedemo.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", ENDITEM, 
		LAST);

	//lr_start_transaction("Choose city and click find");

	web_add_auto_header("Origin", 
		"https://blazedemo.com");

	lr_think_time(28);

	web_submit_form("reserve.php", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=fromPort", "Value={From}", ENDITEM, 
		"Name=toPort", "Value={ToPort}", ENDITEM, 
		LAST);
	

	web_websocket_send("ID=1", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"{id}\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	

	/*Connection ID 1 received buffer WebSocketReceive0*/

	lr_start_transaction("Choose flight");

	web_submit_form("purchase.php", 
		"Ordinal=1", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		LAST);

	lr_end_transaction("Choose flight", LR_AUTO);

	
	lr_think_time(30);

	//lr_start_transaction("Post credentials");

	web_submit_form("confirmation.php", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=inputName", "Value={Name}", ENDITEM, 
		"Name=address", "Value={address}", ENDITEM, 
		"Name=city", "Value={city}", ENDITEM, 
		"Name=state", "Value={state}", ENDITEM, 
		"Name=zipCode", "Value={zipCode}", ENDITEM, 
		"Name=cardType", "Value={cardType}", ENDITEM, 
		"Name=creditCardNumber", "Value={creditNumber}", ENDITEM, 
		"Name=creditCardMonth", "Value={cardMonth}", ENDITEM, 
		"Name=creditCardYear", "Value={cardYear}", ENDITEM, 
		"Name=nameOnCard", "Value={nameonCard}", ENDITEM, 
		"Name=rememberMe", "Value=<OFF>", ENDITEM, 
		LAST);

	return 0;
}