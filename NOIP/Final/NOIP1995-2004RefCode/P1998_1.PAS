program p1998_1(input,output);
var k,count,i,j,s:integer;a:array[0..9] of integer;
begin
    assign(output,'three.out');
    rewrite(output);
    for i:=123 to 329 do begin
       fillchar(a,sizeof(a),0);
       for j:=1 to 3 do begin
          s:=i*j;
          while s>0 do begin a[(s mod 10)]:=1;s:=s div 10;end;
       end;
       count:=0;
       for k:=1 to 9 do count:=count+a[k];
       if count=9 then begin write(i,' ',2*i,' ',3*i);writeln;end;
    end;
    close(output);
end.
