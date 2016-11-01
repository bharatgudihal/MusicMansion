package com.epicgames.ue4;

import com.YourCompany.MusicMansion.OBBDownloaderService;
import com.YourCompany.MusicMansion.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

