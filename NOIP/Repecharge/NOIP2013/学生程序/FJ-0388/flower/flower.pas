program flower;
var a,b,c,d,e,n:longint;
h,g:array[1..100000]of longint;
begin
 assign(input,'flower.in');
 reset(input);
 assign(output,'flower.out');
 rewrite(output);
 readln(n);
 for a:=1 to n do
  read(h[a]);
 for a:=1 to n do
  for b:=1 to n do
   if h[a]<h[b] then
    begin
     c:=h[a];
     h[a]:=h[b];
     h[b]:=c;
    end;
 d:=1;
 for a:=1 to n do
  if h[a]>d then d:=h[a];
 e:=(d div 2)+(d mod 2);


write(e);
close(input);
close(output);
end.

{program HelloMac;}

{Demo of a simple program which uses the classic Macintosh Toolbox.
 It also shows how to include a mac style resource file.}

{USES
	MacOS;}


{var
	window: WindowPtr;

begin
	InitGraf(@qd.thePort);
	InitFonts;
	InitWindows;
	InitMenus;
	TEInit;
	InitDialogs(nil);
	InitCursor;

	window:= GetNewWindow(128, nil, WindowPtr(-1));
	if window <> nil then
		begin
			SetPort(window);
			MoveTo(20,20);
			DrawString('Hello Free Pascal on the Mac :-)');

			repeat
			until Button;
		end;

end. }
