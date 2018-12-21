open BsReactNative;

let component = ReasonReact.statelessComponent("PostButton");

let styles = StyleSheet.create(
  Style.{
    "submit": style([
      borderRadius(5.),
      width(Pct(100.)),
      paddingBottom(Pt(10.)),
      backgroundColor(String("rgb(175, 100, 200)")),
      alignSelf(Center),
      borderBottomWidth(4.),
      borderColor(String("rgba(175,100,200,0.58)"))
    ]),
    "submitTitle": style([
      fontSize(Float(20.)),
      fontFamily("Pacifico"),
      color(String("white")),
      textAlign(Center)
    ])
  }
);

let make = (~onPress , _children) => {
    ...component,
    render: (_self) => {
        <TouchableOpacity style=styles##submit onPress>
            <Text style=styles##submitTitle>{ReasonReact.string("post")}</Text>
        </TouchableOpacity>
    }
}
            