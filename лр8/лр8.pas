const
    days: array[0..6] of string = ('воскресенье','суббота','пятница','четверг','среда','вторник','понедельник');

type date = record
    d, m, y, dw: integer;
end;

function days_in_month(month: integer; year: integer) : integer;
var res: integer;
begin
  case month of
    1, 3, 5, 7, 8, 10, 12: res := 31;
    4, 6, 9, 11: res := 30;
  end;
  if (month = 2) then
    begin
      if (year mod 100 = 0) then
        if (year mod 400 = 0) then
          res := 29
        else
          res := 28
      else
        if (year mod 4 = 0) then
          res := 29
        else
          res := 28;
    end;
  days_in_month := res;
end;

var 
  evnt: date;
  t1, t2: integer;
  
begin
  writeln('Введите дату');
  
  write('День: '); read(evnt.d);
  write('Месяц: '); read(evnt.m);
  write('Год: '); read(evnt.y);
  write('День недели (число, где 1 - понедельник, 2 - вторник и т.д.): '); read(evnt.dw);
  
  while evnt.m > 1 do
    begin
      evnt.m := evnt.m - 1;
      t1 := days_in_month(evnt.m,evnt.y);
      evnt.d := evnt.d + t1;
    end;
    
  t2 := ((evnt.d - 1) mod 7);
  evnt.dw := (7 + t2 - evnt.dw) mod 7;
  write(days[evnt.dw]);
end.
