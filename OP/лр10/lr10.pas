procedure open_to_rewrite(var fi: text; f_name: string; var fo: text);
begin
  assign(fi,f_name);
  assign(fo,'output.txt');
  reset(fi);
  rewrite(fo);
end;

procedure close_to_rewrite(var fi: text; var fo: text);
begin
  close(fi);
  close(fo);
end;

procedure to_floating_point(f_name: string);
var fi, fo: text;
    a: real;
begin
  open_to_rewrite(fi,f_name,fo);
  
  while not(Eof(fi)) do
    begin
      read(fi,a);
      writeFormat(fo,'{0:e2} ',a);
    end;
    
  close_to_rewrite(fi,fo);
end;

var f_name: string;

begin
  writeln('Перевод чисел с фиксированной точкой в числа с плавающей точкой');
  
  writeln('Введите имя файла с данными');
  read(f_name);
  
  to_floating_point(f_name);
end.