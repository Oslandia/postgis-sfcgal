REM $Id: upgrade_geocoder.bat 9691 2012-04-29 15:25:55Z robe $
set PGPORT=5432
set PGHOST=localhost
set PGUSER=postgres
set PGPASSWORD=yourpasswordhere
set THEDB=geocoder
set PGBIN=C:\Program Files\PostgreSQL\8.4\bin
set PGCONTRIB=C:\Program Files\PostgreSQL\8.4\share\contrib
"%PGBIN%\psql"  -d "%THEDB%" -f "upgrade_geocode.sql"
"%PGBIN%\psql"  -d "%THEDB%" -f "tiger_loader_2011.sql"
cd regress
"%PGBIN%\psql" -t -f regress.sql
pause

