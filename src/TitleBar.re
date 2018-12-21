open BsReactNative;

let component = ReasonReact.statelessComponent("TitleBar");

let styles = StyleSheet.create(
  Style.{
    "title": style([
      height(Pt(50.)),
      width(Pct(100.)),
      display(Flex),
      alignItems(Center)
    ]),
    "bg": style([
      position(Absolute),
      height(Pct(100.)),
      width(Pct(100.)),
      resizeMode(Cover)
    ]),
    "logo": style([
      width(Pt(100.)),
      height(Pt(40.)),
    ])
  }
);

let make = (_children) => {
    ...component,
    render: (_self) =>
        <View style=styles##title>
          <ImageBackground
            style=styles##bg
            source=(`Required(Packager.require( "../../../assets/bg_bar.png"))) />
          <Image
            style=styles##logo
            source=(`Required(Packager.require( "../../../assets/logo.png"))) />
        </View>
}