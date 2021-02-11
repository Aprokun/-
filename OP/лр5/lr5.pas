const
  M = 99;
  N = 99;
type
  t_matrix = array[0..m,0..n] of integer;
  t_iterator = integer;

{процедура ввода матрицы matrix размера m строк и n столбцов}
procedure read_matrix(var a: t_matrix; p: integer);
var i,j: integer;
begin
  for i := 0 to p-1 do
    for j := 0 to p-1 do
      read(a[i][j]);
end;

{процедура поиска выше обратной диагонали}
procedure search_above(a: t_matrix; p: integer; max: integer; var sum: integer);
var i,j: integer;
begin
  for i := 0 to p-1 do
    begin
      for j := i downto 0 do
        if (a[j][i-j] > max) then
          max := a[j][i-j];
      sum := sum + max;  
      max := 0;
    end;
end;

{процедура поиска ниже обратной диагонали}
procedure search_below(a: t_matrix; p:integer; max: integer; var sum: integer);
var i,j: integer;
begin
  begin
  for j := 1 to p-1 do
    begin
      for i := j to p-1 do
        if (a[p - 1 - (i - j)][i] > max) then
          max := a[p - 1 - (i - j)][i];
      sum := sum + max;
      max := 0;
    end
  end;  
end;

var
  a: t_matrix;
  p, max, sum: integer;

begin
  max := 0;
  sum := 0;
  
  writeln('Ввод квадратной матрицы');
  
  write('Ввод порядка матрицы: ');
  read(p);
  
  writeln('Вводите значения матрицы по строками');
  read_matrix(a,p);
 
  search_above(a,p,max,sum);
  search_below(a,p,max,sum);
      
  write('Сумма максимальных значений псевдодиагоналей равна = ');
  write(sum);
end.