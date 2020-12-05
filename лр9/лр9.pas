const
  ZN: set of char = [' ','.',',',':','?','!'];
  VOWEL: set of char = ['а','о','у','э','ы','я','е','ю','и','А','О','У','Э','Ы','Я','Е','Ю','И'];
  
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

function count_vowel(w1: string; w2: string) : integer;
var i, len:integer;
    c: integer;
begin
  len := length(w2);
  
  for i := 1 to len do
    if (w2[i] in w1) and (w2[i] in VOWEL) then 
      c := c + 1; 
  count_vowel := c;
end;

procedure match_words(s1: string; s2: string);
var
  i, j, len1, len2, c, c_max: integer;
  w1, w2, res_w: string;
begin
  i := 1; 
  j := 1;
  len1 := length(s1);
  len2 := length(s2);
  
  while (i < len1) do
    begin
      w1 := get_word(s1,i);
      while (j < len2) do
        begin      
          w2 := get_word(s2,j);
          c := count_vowel(w1,w2);
          if (c > c_max) then
            begin
              c_max := c;
              res_w := w2;
            end;
        end;
        j := 1;
        c_max := 0;
        if (res_w = '') then
          writeln(w1,' ==== нет подходящего слова')
        else 
          writeln(w1,' ==== ',res_w);
    end;    
end;

var
  s1, s2: string;

begin
  
  writeln('Введите первую строку');
  readln(s1);
  
  writeln('Введите вторую строку');
  readln(s2);
  
  writeln('Результат:');
  match_words(s1,s2);
  
end.