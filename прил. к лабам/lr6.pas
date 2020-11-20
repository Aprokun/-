const
  zn = [' ','.',',',':','?','!'];
  
function get_word(str: string; var i: integer) : string;
var w: string;
    len: integer;
begin
  len := length(str);
  while (str[i] in zn) and (i < len) do
    i := i + 1;
  w := '';
  while (i <= len) and not(str[i] in zn) do
    begin
      w := w + str[i];
      i := i + 1;
    end;
  get_word := w;
end;

function find_repeats(str: string) : boolean;
var i,j: integer;
    wrd1, wrd2: string;
    len: integer;
    res: boolean;
begin
  res := false;
  i := 1;
  str := str + ' ';
  len := length(str);
  while i < len do
    begin 
      wrd1 := get_word(str,i);
      j := i;
      while (j < len) do
        begin
          wrd2 := get_word(str,j);
          if (wrd1 = wrd2) then
            res := true;
          wrd2 := '';
        end;
      wrd1 := '';
    end;
  find_repeats := res;
end;

var
  str: string;
  flag: boolean;
  is_repeat: boolean;
begin
  writeln('Введите строку');
  read(str);
  is_repeat := find_repeats(str);
  
  if (is_repeat = true) then
    writeln('В данной строке есть повторы слов')
  else writeln('В данной строке нет повторов слов')
end.