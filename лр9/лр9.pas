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

function get_vowel(w: string) : set of char;
var res: set of char;
    i, len: integer;
begin
  len := length(w);
  
  for i := 1 to len do
    if (w[i] in VOWEL) then
      res := res + [w[i]];
  
  get_vowel := res;
end;

function pick_word(str: string; wv: set of char) : string;
var j, len: integer;
    w, res: string;
    w2v: set of char;
begin
  j := 1;
  len := length(str);
  res := '';
  
  while (j < len) do
    begin      
      w := get_word(str,j);
      w2v := get_vowel(w);
      
      if (wv = w2v) then
        res := w;
    end;
   pick_word := res;
end;

procedure match_words(s1: string; s2: string);
var
  i, len: integer;
  w1, w2, res_w: string;
  w1v, w2v: set of char;
begin
  i := 1; 
  len := length(s1);
  
  while (i < len) do
    begin
      w1 := get_word(s1,i);
      w1v := get_vowel(w1);
      
      res_w := pick_word(s2,w1v);
      if (res_w = '') then
        writeln(w1,' ==== нет подходящего слова')
      else 
        writeln(w1,' ==== ',res_w);
      res_w := '';
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
