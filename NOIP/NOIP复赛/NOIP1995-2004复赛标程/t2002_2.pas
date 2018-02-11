program t2002_2;
type point=^node;
     node=record
         s:string;step:integer;next:point;
     end;
var i,j,n,st:integer;
    c,d:string;
    a,b:array[0..6] of string;
    head1,tail1,head2,tail2,p1,p2,t1,t2,q:point;
    found:boolean;

function find(c,d:string;k:integer):integer;
var i,j:integer;ok:boolean;
begin
    i:=k;ok:=false;
    while not ok and (i+length(d)-1<=length(c)) do begin
        for j:=1 to length(d) do
            if c[i+j-1]<>d[j] then break;
        if (j=length(d)) and (c[i+j-1]=d[j]) then ok:=true
           else i:=i+1;
    end;
    if ok then find:=i else find:=0;
end;

function change(c,b:string;j,n:integer):string;
var d:string;nc,nb,i:integer;
begin
     nc:=length(c);nb:=length(b);
     for i:=nc downto j+n do
         d[i+nb-n]:=c[i];
     for i:=j-1 downto 1 do d[i]:=c[i];
     for i:=j to j+nb-1 do d[i]:=b[i-j+1];
     d[0]:=chr(length(c)+nb-n);
     change:=d;
end;

procedure add(var tail:point;d:string;i:integer);
var q:point;
begin
     new(q);
     q^.s:=d;q^.step:=i;q^.next:=nil;
     tail^.next:=q;tail:=q;
end;

procedure one_two(c:string;n:integer);
var i,j:integer;
begin
    i:=1;
    while c[i]<>' ' do begin a[n][i]:=c[i];i:=i+1;end;
    a[n][0]:=chr(i-1);
    i:=i+1;j:=0;
    while i<=length(c) do begin j:=j+1;b[n][j]:=c[i];i:=i+1;end;
    b[n][0]:=chr(j);
end;

begin
      assign(input,'b.in');
      reset(input);
      readln(c);
      one_two(c,0);
      if a[0]=b[0] then begin writeln(0);close(input);close(output);halt;end;
      readln(c);i:=1;
      while not eof(input) and (i<=6) do begin
          one_two(c,i);
          i:=i+1;
          readln(c);
      end;
      n:=i;
      if length(c)>1 then one_two(c,n);
      close(input);
      assign(output,'b.out');
      rewrite(output);
      new(head1);head1^.s:='';head1^.next:=nil;head1^.step:=0;
      new(p1);p1^.s:=a[0];p1^.next:=nil;p1^.step:=0;
      head1^.next:=p1;tail1:=p1;
      new(head2);head2^.s:='';head2^.next:=nil;head2^.step:=0;
      new(p2);p2^.s:=b[0];p2^.next:=nil;p2^.step:=0;
      head2^.next:=p2;tail2:=p2;

      while ((p1<>nil) and (p1^.step<10)) and ((p2<>nil) and (p2^.step<10)) do begin
          t1:=tail1;t2:=tail2;
          while (p1<>t1^.next) and (p1^.step<10) do begin
             c:=p1^.s;st:=p1^.step;
             for i:=1 to n do begin
                 j:=find(c,a[i],1);
                 while j<>0 do begin
                     d:=change(c,b[i],j,length(a[i]));
                     q:=head2^.next;found:=false;
                     while not found and (q^.step+st<=10) and (q<>nil) do begin
                         if d=q^.s then found:=true
                            else q:=q^.next;
                     end;
                     if found then begin writeln(st+1+q^.step);close(output);halt;end;
                     add(tail1,d,st+1);
                     j:=find(c,a[i],j+1);
                 end;
             end;
             p1:=p1^.next;
          end;
          while (p2<>t2^.next) and (p2^.step<10) do begin
             c:=p2^.s;st:=p2^.step;
             for i:=1 to n do begin
                 j:=find(c,b[i],1);
                 while j<>0 do begin
                     d:=change(c,a[i],j,length(b[i]));
                     q:=head1^.next;found:=false;
                     while not found and (q^.step+st<=10) and (q<>nil) do begin
                         if d=q^.s then found:=true
                            else q:=q^.next;
                     end;
                     if found then begin writeln(st+1+q^.step);close(output);halt;end;
                     add(tail2,d,st+1);
                     j:=find(c,b[i],j+1);
                 end;
             end;
             p2:=p2^.next;
          end;
      end;

      writeln('NO ANSWER!');
      close(output);
end.
