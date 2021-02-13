//Дан символьный файл. Сократить число пробелов между словами до одного.

procedure open_to_rewrite(var f: file of char; f_name: string);
begin
  assign(f,f_name);
  reset(f);
end;

function skip_white_space(f: file of char) : integer;
var c: char;
    res: integer;
begin
  Read(f,c);
  while (c = ' ') and not Eof(f) do
    begin
      Read(f,c);
    end;
    
  res := FilePos(f) - 1;
  skip_white_space := res;
end;

procedure cut_back_white_space(f_name: string);
var f: file of char;
    c: char;
    ir, iw: integer;
begin
  open_to_rewrite(f,f_name);
  
  ir := 0;
  iw := 0;
  
  while not Eof(f) do 
  begin
    read(f,c);
    seek(f,FilePos(f)-1);
    write(f,' ');
    ir := ir + 1;
    
    if (c = ' ') then
      begin
        iw := iw + 1;
        ir := skip_white_space(f);
        seek(f,ir);
      end
    else
      begin
        seek(f,iw);
        write(f,c);
        iw := iw + 1;
        seek(f,ir);
      end;
  end;

  close(f);
end;

var f_name: string;

begin
  writeln('Введите имя файла');
  read(f_name);
  
  cut_back_white_space(f_name);
end.