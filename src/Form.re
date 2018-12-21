open BsReactNative;

let component = ReasonReact.statelessComponent("Form");

let styles = StyleSheet.create(
  Style.{
    "form": style([
      position(Absolute),
      height(Pct(100.)),
      width(Pct(100.)),
      backgroundColor(String("rgba(0, 0, 0, 0.58)")),
      top(Pt(0.)),
      zIndex(2),
      display(Flex),
      justifyContent(Center),
      alignItems(Center)
    ]),
    "box": style([
      padding(Pt(28.)),
      width(Pct(90.)),
      borderRadius(10.),
      backgroundColor(String("white"))
    ]),
    "inputText": style([
      backgroundColor(String("rgba(175, 100, 200, 0.1)")),
      borderRadius(10.),
      padding(Pt(8.)),
      marginBottom(Pt(20.)),
      fontSize(Float(18.)),
      color(String("black")),
      fontFamily("Amaranth-Regular")
    ]),
    "inputAuthor": style([
      backgroundColor(String("rgba(100,100, 100, 0.1)")),
      borderRadius(10.),
      padding(Pt(8.)),
      marginBottom(Pt(20.)),
      fontSize(Float(16.)),
      color(String("black")),
      fontFamily("Amaranth-Regular")
    ]),
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

let make = (_children) => {
    ...component,
    render: (_self) =>
        <View style=styles##form>
          <View style=styles##box>
            <Text>{ReasonReact.string("TEXT TO POST")}</Text>
            <TextInput
              autoFocus=true
              style=styles##inputText
              multiline=true
              numberOfLines=3
              />
            <Text>{ReasonReact.string("BY")}</Text>
            <TextInput
              autoFocus=false
              style=styles##inputAuthor
              multiline=false
              />
            <PostButton onPress={() => ()}/>
          </View>
        </View>
}