#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Fonksiyonlar� belirttik
void UyeEkle();
void UyeListele();
void UyeSil();
void UyeGuncelle();
void HocaEkle();
void HocaSil();
void HocaListele();
void HocaGuncelle();
void ProgramEkle();
void ProgramListele();

int main() {
	
	bool kontrol=true,uyeListeleKontrol=true,hocaKontrol=true,programKontrol=true;
	char secim;
	do{
		//                   ANA MEN�
		printf("-----SPOR SALONU KAYIT SISTEMI-----\n");
		printf("1 - Uye Listeleme\n");
		printf("2 - Hoca Listeleme\n");
		printf("3 - Program Listeleme\n");
		printf("0 - Cikis\n");
		printf("Yukaridaki islemlerden bir tanesini seciniz:");
		scanf("%s",&secim);//se�im de�i�kenine kullan�c�dan de�er ald���m�z b�l�m
		if(secim=='1')
		{
			//        �ye listelemenin alt men�s�
			do{
			
				UyeListele();//�ye listeleme fonksiyonu �al���r
				printf("Yukaridaki islemlerden bir tanesini seciniz:");
				scanf("%s",&secim);//se�im de�i�kenine kullan�c�dan de�er ald���m�z b�l�m
				
				if(secim=='+')
				{	
					//database.txt dosyam�za �yelerin kay�t edildi�i k�s�m
					UyeEkle();
					uyeListeleKontrol=true;
				
				}else if(secim=='-'){
					//database.txt dosyam�za �yelerin silindi�i k�s�m
					UyeSil();
					uyeListeleKontrol=true;
				}else if(secim=='*'){
					//database.txt dosyam�za �yelerin g�ncellendi�i k�s�m
					UyeGuncelle();
					uyeListeleKontrol=true;
					
				}else if(secim=='0'){
					printf("Geri Gidiliyor...\n\n");
					uyeListeleKontrol=false;
				}
				else
				{
					printf("Lutfen Yukarida gordugunuz islemlerden bir tanesini seciniz.\n\n");
					uyeListeleKontrol=true;
				}
			}while(uyeListeleKontrol);
		}
		
		else if(secim=='2')
		{
			
			//          Hocalar�n listelendi�i b�l�m
			do{
			HocaListele();
			printf("\n--------------------------------------------\n");	
			printf("+ - Hoca Ekleme\n");
			printf("- - Hoca Silme\n");
			printf("* - Hoca Guncelleme\n");
			printf("0 - Cikis\n");
			printf("Yukaridaki islemlerden bir tanesini seciniz:");
			scanf("%s",&secim);//se�im de�i�kenine kullan�c�dan de�er ald���m�z b�l�m
			if(secim=='+')
			{
				//hocadatabase.txt dosyam�za hocalar�n kay�t edildi�i k�s�m
				HocaEkle();
				hocaKontrol=true;
			}else if(secim=='-'){
				//hocadatabase.txt dosyam�za hocalar�n silindi�i k�s�m
				HocaSil();
				hocaKontrol=true;
			}else if(secim=='*'){
					//hocadatabase.txt dosyam�za hocalar�n g�ncellendi�i k�s�m
				HocaGuncelle();
				hocaKontrol=true;
			}else if(secim=='0'){
				printf("Geri gidiliyor...\n\n");
				hocaKontrol=false;
			}else{
				printf("L�tfen yukar�daki i�lemlerden birini se�iniz.\n\n");
				hocaKontrol=true;
			}
			}while(hocaKontrol);
			
		}
		else if(secim=='3')
		{
			//        Programlar�n�n listelendi�i b�l�m
			do{
				ProgramListele();
				printf("\n--------------------------------------------\n");	
				printf("+ - Program Ekleme\n");
				printf("0 - Cikis\n");
				printf("Bir secim yapiniz:");
				scanf("%s",&secim);
				if(secim=='+'){
						//programdatabase.txt dosyam�za programlar�n eklendi�i k�s�m
					ProgramEkle();
					programKontrol=true;
				}else if(secim=='0'){
					printf("Geri gidiliyor...\n\n");
					programKontrol=false;
				}
				
			}while(programKontrol);
		
		
		
		}
		else if(secim=='0')
		{
			//                 Program� kapatan b�l�m 
			printf("CIKIS YAPILIYOR....");
			kontrol=false;
			
		}
		else
		{
			//         Yanl�� bir se�im yap�l�rsa ekranda g�z�kecek b�l�m
		printf("Lutfen Yukarida gordugunuz islemlerden bir tanesini seciniz\n");	
		kontrol=true;
		}
		
	}while(kontrol);
	
	
	return 0;
}

void UyeEkle()
{
	char adi[20];
	char soyadi[20];
	char cinsiyetString[10];
	char cinsiyetChar;
	char tc[12],tcAra[12];
	int yas,gun,ay,yil,cnsyt,boy,hocaSec,programSec;
	float kilo;
	bool cinsiyetKontrol=true,yasKontrol=true;	
	FILE *dosya;
	dosya = fopen("uyedatabase.txt","a");//dosyam�z� ekleme modunda a��yoruz.
		if(dosya!=NULL)//dosya var m� yok mu kontrol ediyoruz
		{
			/*----------------Kullan�can Uyelerin Bilgilerinin al�nd��� k�s�m----------------*/
			printf("-------------------Uye Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Kayit etmek istediginiz uyenin Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nKayit etmek istediginiz uyenin adini giriniz:");
			scanf("%s",&adi);
			printf("Kayit etmek istediginiz uyenin soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("Kayit etmek istediginiz uyenin cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			/*--------------------Cinsiyet karakterini konrol etti�imiz yer*/
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

			printf("Kayit etmek istediginiz uyenin yasini giriniz:");
			scanf("%d",&yas);
			printf("Kayit etmek istediginiz uyenin boyunu giriniz(orn:185cm):");
			scanf("%d",&boy);
			printf("Kayit etmek istediginiz uyenin kilosunu giriniz(orn:75.8):");
			scanf("%f",&kilo);
			printf("Kayit etmek istediginiz uyenin giris tarihini giriniz =>\n");
			printf("Gun: ");
			scanf("%d",&gun);
			printf("Ay: ");
			scanf("%d",&ay);
			printf("Yil: ");
			scanf("%d",&yil);
			
			ProgramListele();
			/*----------------------------------------�DEAL K�LONUN HESAPLANDI�I B�L�M----------------------------------------*/
			float erkek=0.9,kadin=0.8,idealKilo,fark;
			
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				idealKilo=(boy-100+yas/10)*erkek;
				fark=kilo - idealKilo;
			}else{
				float idealKilo=(boy-100+yas/10)*kadin;
				float fark=(kilo - idealKilo);
				
			}
			if(fark<0) printf("Zayifsiniz.kilo alma programini secmeniz onerilir.");
				else if(fark>=0 && fark<=10) printf("Normal Kilolusunuz.Kas kutlesi kazanma programini secmeniz onerilir ");
				else if(fark>=11 && fark<=20) printf("Fazla Kilolusunuz.Kilo verme programi veya kas kutlesi programini secmeniz onerilir");
				else if(fark>=21 && fark<=29) printf("Obezsiniz.Kilo verme programini secmeniz onerilir");
				else if(fark>=30) printf("ileri Derecede Obezsiniz.Kilo verme programini secmeniz onerilir");
				else printf("Kilo Hesaplanamadi");
			
			printf("\n\nProgram seciniz:");
			scanf("%d",&programSec);
			
			HocaListele();
			printf("Hoca seciniz:");
			scanf("%d",&hocaSec);
			
			
				
			//---------------------------Kullan�c�dan ald���m�z verileri 'uyedatabase.txt' dosyam�za kay�t ediyoruz.---------------------------
			fprintf(dosya,"() %s - %s - %s - %d -%s- %d - %f - Kayit Tarihi: %d / %d / %d | Ideal Kilo: %.2f | Hoca Secimi: %d | Program Secimi: %d \n",tc,adi,soyadi, yas, cinsiyetString,boy,kilo,gun,ay,yil,idealKilo,hocaSec,programSec);
			fclose(dosya);	
		}
		else{
			printf("Dosya bulunamadi...");
			fclose(dosya);
		}

}

void UyeListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("uyedatabase.txt","r");//'uyedatabase.txt'dosyam�z� okuma modunda a��yoruz.
	char karakter;
	if(dosya != NULL)//dosyan�n olup olmad���n� kontrol etti�imiz b�l�m
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyan�n i�indeki b�t�n karakterleri d�ng� ile ald���m�z b�l�m !feof fonksiyonu dosyan�n sonuna gelinip gelinmedi�ini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAK� SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // e�er karakter ')' ise sat�r� yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
		printf("\n--------------------------------------------\n");	
			printf("+ - Uye Ekleme\n");
			printf("- - Uye Silme\n");
			printf("* - Uye Guncelleme\n");
			printf("0 - Cikis\n");
	fclose(dosya);
}

void UyeSil(){
	FILE *dosya, *dosyayeni;   
	dosyayeni = fopen("yeniuyedatabase.txt","w");//'yeniuyedatabase.txt' dosyam�z� yazma modunda a��yoruz.
	dosya = fopen("uyedatabase.txt","r");//'uyedatabase.txt' dosyam�z� okuma modunda a��yoruz.
	int satir=0;
	printf("hangi satirdaki uyeyi silmek istiyorsunuz: ");
	scanf("%d",&satir);//kullan�c�dan silinecek sat�r� al�yoruz.
	
	char line[256];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)
			fputs(line, dosyayeni);//'uyedatabase.txt' dosyadaki verileri yeni dosyaya yaz�yoruz.
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("uyedatabase.txt");//'uyedatabase.txt' dosyas�n� siliyoruz.
	rename("yeniuyedatabase.txt", "uyedatabase.txt");//'yeniuyedatabase.txt' dosyam�z�n ad�n� 'uyedatabase' olarak de�i�tiriyoruz.
	printf("kayit silindi. bir tusa basin.\n");
}

	void UyeGuncelle(){
	char adi[20];
	char soyadi[20];
	char cinsiyetString[10];
	char cinsiyetChar;
	char tc[12],tcAra[12];
	int yas,gun,ay,yil,cnsyt,boy,hocaSec,programSec,satir;
	float kilo;
	bool cinsiyetKontrol=true,yasKontrol=true;	
	
	FILE *dosya, *dosyayeni;   
	dosya = fopen("uyedatabase.txt","r");
	dosyayeni = fopen("yeniuyedatabase.txt","w");
	//yeniuyedatabase.txt ADINDA YEN� B�R TXT DOSYASI A�IP G�NCELLEN�CEK SATIRDAK� VER�LER� ALIP YEN� TXT DOSYAMIZA AYNI SATIRA ALDI�IMIZ VER�LER� G�R�YORUZ
	printf("Hangi satiri guncelleyeceksiniz: ");
	scanf("%d",&satir);

		printf("-------------------Uye G�ncelleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("G�ncellemek etmek istediginiz uyenin Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nG�ncellemek etmek istediginiz uyenin adini giriniz:");
			scanf("%s",&adi);
			printf("G�ncellemek etmek istediginiz uyenin soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("G�ncellemek etmek istediginiz uyenin cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

			printf("G�ncellemek etmek istediginiz uyenin yasini giriniz:");
			scanf("%d",&yas);
			printf("G�ncellemek etmek istediginiz uyenin boyunu giriniz(orn:185):");
			scanf("%d",&boy);
			printf("G�ncellemek etmek istediginiz uyenin kilosunu giriniz(orn:75.8):");
			scanf("%f",&kilo);
			printf("G�ncellemek etmek istediginiz uyenin giris tarihini giriniz =>\n");
			printf("Gun: ");
			scanf("%d",&gun);
			printf("Ay: ");
			scanf("%d",&ay);
			printf("Yil: ");
			scanf("%d",&yil);
			
			
			ProgramListele();
			/*----------------------------------------�DEAL K�LONUN HESAPLANDI�I B�L�M----------------------------------------*/
			float erkek=0.9,kadin=0.8,idealKilo,fark;
			
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				idealKilo=(boy-100+yas/10)*erkek;
				fark=kilo - idealKilo;
			}else{
				float idealKilo=(boy-100+yas/10)*kadin;
				float fark=(kilo - idealKilo);
				
			}
			if(fark<0) printf("Zayifsiniz.kilo alma programini secmeniz onerilir.");
				else if(fark>=0 && fark<=10) printf("Normal Kilolusunuz.Kas kutlesi kazanma programini secmeniz onerilir ");
				else if(fark>=11 && fark<=20) printf("Fazla Kilolusunuz.Kilo verme programi veya kas kutlesi programini secmeniz onerilir");
				else if(fark>=21 && fark<=29) printf("Obezsiniz.Kilo verme programini secmeniz onerilir");
				else if(fark>=30) printf("ileri Derecede Obezsiniz.Kilo verme programini secmeniz onerilir");
				else printf("Kilo Hesaplanamadi");
			
			printf("\n\nProgram seciniz:");
			scanf("%d",&programSec);
			
			HocaListele();
			printf("Hoca seciniz:");
			scanf("%d",&hocaSec);
			
			
			
			
			
			
			
	
	
	char line[250];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)//g�ncellemek istedi�imiz sat�ra gelip gelmedi�imizi kontrol ediyor g�ncellemek istemedi�imiz sat�ra gelmemi�se if blo�unun i�indeki kodlar� �al��t�r�yor
			fputs(line, dosyayeni);//eski dosyan�n sat�r�ndaki b�t�n karakterleri yeni dosyaya yaz�yor
	    else{
		
			fprintf(dosyayeni,"() %s - %s - %s - %d -%s- %d - %f - Kayit Tarihi: %d / %d / %d | Ideal Kilo: %.2f | Hoca Secimi: %d | Program Secimi: %d \n",tc,adi,soyadi, yas, cinsiyetString,boy,kilo,gun,ay,yil,idealKilo,hocaSec,programSec);
			
			}
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("uyedatabase.txt");//eski dosyay� siliyor
	rename("yeniuyedatabase.txt", "uyedatabase.txt");//yeni dosyan�n ad�n� eski dosyan�n ad�yla de�i�tiriyor.
	printf("Kayit guncellendi....\n");
	}
	
void HocaEkle(){
		
		char adi[20];
		char soyadi[20];
		char cinsiyetString[10];
		char cinsiyetChar;
		char tc[12],tcAra[12];
		bool cinsiyetKontrol=true,yasKontrol=true;	
		FILE *dosya;
		dosya = fopen("hocadatabase.txt","a");
		if(dosya!=NULL)
		{
			printf("-------------------Hoca Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Kayit etmek istediginiz hoca Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nKayit etmek istediginiz hoca adini giriniz:");
			scanf("%s",&adi);
			printf("Kayit etmek istediginiz hoca soyadini giriniz:");
			scanf("%s",&soyadi);
			do{
				printf("Kayit etmek istediginiz hoca cinsiyetini seciniz(E/K):");
				scanf("%s",&cinsiyetChar);
				if(cinsiyetChar=='e'||cinsiyetChar=='E')
				{
					strcpy(cinsiyetString, "Erkek");
					cinsiyetKontrol=false;
				}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
					strcpy(cinsiyetString, "Kadin");
					cinsiyetKontrol=false;
				}else{
					printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
					cinsiyetKontrol=true;
				}	
			}while(cinsiyetKontrol);
			
			fprintf(dosya,"() %s - %s - %s - %s \n",tc,adi,soyadi,cinsiyetString);
			fclose(dosya);
		
		}else{
			printf("Dosya Bulunamad�");
			fclose(dosya);
		}	
	}
void HocaSil(){
	FILE *dosya, *dosyayeni;   
	dosyayeni = fopen("yenihocadatabase.txt","w");//'yeniuyedatabase.txt' dosyam�z� yazma modunda a��yoruz.
	dosya = fopen("hocadatabase.txt","r");//'uyedatabase.txt' dosyam�z� okuma modunda a��yoruz.
	int satir=0;
	printf("hangi satirdaki hocayi silmek istiyorsunuz: ");
	scanf("%d",&satir);//kullan�c�dan silinecek sat�r� al�yoruz.
	
	char line[256];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)
			fputs(line, dosyayeni);//'uyedatabase.txt' dosyadaki verileri yeni dosyaya yaz�yoruz.
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("hocadatabase.txt");//'uyedatabase.txt' dosyas�n� siliyoruz.
	rename("yenihocadatabase.txt", "hocadatabase.txt");//'yeniuyedatabase.txt' dosyam�z�n ad�n� 'uyedatabase' olarak de�i�tiriyoruz.
	printf("kayit silindi. bir tusa basin.\n");
		
		
	}
void HocaListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("hocadatabase.txt","r");//'hocadatabase.txt'dosyam�z� okuma modunda a��yoruz.
	char karakter,sonraki;
	if(dosya != NULL)//dosyan�n olup olmad���n� kontrol etti�imiz b�l�m
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyan�n i�indeki b�t�n karakterleri d�ng� ile ald���m�z b�l�m !feof fonksiyonu dosyan�n sonuna gelinip gelinmedi�ini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAK� SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // e�er karakter ')' ise sat�r� yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
		
	fclose(dosya);
}
void HocaGuncelle(){
		char adi[20];
		char soyadi[20];
		char cinsiyetString[10];
		char cinsiyetChar;
		char tc[12],tcAra[12];
		bool cinsiyetKontrol=true,yasKontrol=true;	
		int satir=0;
		FILE *dosya, *dosyayeni;   
		dosya = fopen("hocadatabase.txt","r");
		dosyayeni = fopen("yenihocadatabase.txt","w");
	
		printf("Hangi satiri guncelleyeceksiniz: ");
		scanf("%d",&satir);

		printf("-------------------Hoca G�ncelleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("G�ncellemek etmek istediginiz hoca Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nG�ncellemek etmek istediginiz hoca adini giriniz:");
			scanf("%s",&adi);
			printf("G�ncellemek etmek istediginiz hoca soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("G�ncellemek etmek istediginiz hoca cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

		char line[100];
		int i=0;
		while(fgets(line, sizeof(line),dosya))
		{
			i++;
			if (i != satir)
				fputs(line, dosyayeni);
		    else{
			
				fprintf(dosyayeni,"() %s - %s - %s - %s - \n",tc,adi,soyadi, cinsiyetString);
				}
		}
		fclose(dosya);
		fclose(dosyayeni);
		remove("hocadatabase.txt");
		rename("yenihocadatabase.txt", "hocadatabase.txt");
		printf("Kayit guncellendi....\n");
		}
void ProgramListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("programdatabase.txt","r");//'hocadatabase.txt'dosyam�z� okuma modunda a��yoruz.
	char karakter;
	if(dosya != NULL)//dosyan�n olup olmad���n� kontrol etti�imiz b�l�m
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyan�n i�indeki b�t�n karakterleri d�ng� ile ald���m�z b�l�m !feof fonksiyonu dosyan�n sonuna gelinip gelinmedi�ini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAK� SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // e�er karakter ')' ise sat�r� yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
	
	fclose(dosya);
}
void ProgramEkle(){
	
		char ProgramAdi[20];	
		FILE *dosya;
		dosya = fopen("programdatabase.txt","a");
		if(dosya!=NULL)
		{
			printf("-------------------Program Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("\nKayit etmek istediginiz program adini giriniz:");
			scanf("%s",&ProgramAdi);
			fprintf(dosya,"() %s \n",ProgramAdi);
			fclose(dosya);
		
		}else{
			printf("Dosya Bulunamad�");
			fclose(dosya);
		}
	
}

